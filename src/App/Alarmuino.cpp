#include "Alarmuino.h"

#include <Ui/SensorPage.h>
#include <Utils/Memory.h>

struct App::Alarmuino::Internal : public Core::SensorsGroup::Listener {
    App::Alarmuino &app;

    explicit Internal(App::Alarmuino &app) : app(app) {}

    void onSensorTriggered(const Core::Sensor &sensor) final {
        changeState(ALERT);
    }

    void onSensorReleased(const Core::Sensor &sensor) final {
        if (!app._sensors.isTriggered()) {
            changeState(IDLE);
        }
    }

    template<class State>
    static void registerState(Alarmuino &app, Alarmuino::Status status) {
        app._enterStateFunction[status] = &State::enter;
        app._leaveStateFunction[status] = &State::leave;
    }

    void changeState(Alarmuino::Status status) {
        if (status == app._status) {
            return;
        }
        DBG_ASSERT(app._leaveStateFunction[app._status] != nullptr);
        DBG_ASSERT(app._enterStateFunction[status] != nullptr);
        app._leaveStateFunction[app._status](app);
        app._enterStateFunction[app._status = status](app);
    }
};

App::Alarmuino::Alarmuino(Core::SensorsGroup &sensors)
        : _homePage("Welcome"),
          _edit_enabled("Activate", *this, &Alarmuino::isEnabled, &Alarmuino::enable),
          _sensorsMenu("Sensors"),
          _alertPage("!! Alert !!", *this, &Alarmuino::isEnabled, &Alarmuino::enable),
          _focus(_homePage),
          _sensors(sensors), _status(DISABLED),
          _enterStateFunction{}, _leaveStateFunction{} {
    Internal::registerState<DisabledState>(*this, DISABLED);
    Internal::registerState<IdleState>(*this, IDLE);
    Internal::registerState<AlertState>(*this, ALERT);

    _homePage.addPage(_edit_enabled);
    _homePage.addPage(_sensorsMenu);
}

App::Alarmuino &App::Alarmuino::addSensorPage(Ui::SensorPage &page) {
    _sensorsMenu.addPage(page);
    return *this;
}

void App::Alarmuino::process(Core::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer) {

    Internal internal(*this);

    // Sensors
    if (isEnabled()) {
        _sensors.dispatchEvents(internal);
    }

    // Inputs
    keyboard.dispatchEvents(_focus);

    // Display
    Utils::Memory::set(&screenBuffer.buffer[0][0], ' ', Ui::ScreenBuffer::NB_COLS * Ui::ScreenBuffer::NB_ROWS);
    _focus.display(screenBuffer);
}

void App::Alarmuino::enable(bool enable) {
    Internal(*this).changeState(enable ? IDLE : DISABLED);
}

bool App::Alarmuino::isEnabled() const {
    return _status != DISABLED;
}

void App::Alarmuino::DisabledState::enter(App::Alarmuino &) {

}

void App::Alarmuino::DisabledState::leave(App::Alarmuino &) {

}

void App::Alarmuino::IdleState::enter(App::Alarmuino &app) {
    app._sensors.reset();
}

void App::Alarmuino::IdleState::leave(App::Alarmuino &) {

}

void App::Alarmuino::AlertState::enter(App::Alarmuino &app) {
    app._focus.reset(app._alertPage);
}

void App::Alarmuino::AlertState::leave(App::Alarmuino &app) {
    app._focus.reset(app._homePage);
}
