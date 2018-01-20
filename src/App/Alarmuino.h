#ifndef ALARMUINO_ALARMUINO_H
#define ALARMUINO_ALARMUINO_H

#include <Ui/MenuPage.h>
#include <Ui/Focus.h>
#include <Ui/Editor/Boolean.h>
#include <Core/Sensor.h>
#include <Core/SensorsGroup.h>

namespace Ui {
    class SensorPage;

    struct ScreenBuffer;

    class Keyboard;
}

namespace App {

    class Alarmuino {
    public:

        explicit Alarmuino(Core::SensorsGroup &sensors);

        Alarmuino &addSensorPage(Ui::SensorPage &page);

        void process(Core::Keyboard &keyboard, Ui::ScreenBuffer &screenBuffer);

        void enable(bool enable);

        bool isEnabled() const;

    private:
        struct Internal;
        //GUI
        Ui::MenuPage _homePage;
        Ui::Editor::Boolean<Alarmuino> _edit_enabled;
        Ui::MenuPage _sensorsMenu;
        Ui::Editor::Boolean<Alarmuino> _alertPage;
        Ui::Focus _focus;

        //Core
        Core::SensorsGroup &_sensors;

        //States
        enum Status {
            DISABLED,
            IDLE,
            ALERT,

            //Meta
            NB_STATUS,
        };
        Status _status;

        typedef void (*TransitionFunction)(Alarmuino &);

        TransitionFunction _enterStateFunction[NB_STATUS];
        TransitionFunction _leaveStateFunction[NB_STATUS];

        struct DisabledState {
            static void enter(Alarmuino &);

            static void leave(Alarmuino &);
        };

        struct IdleState {
            static void enter(Alarmuino &);

            static void leave(Alarmuino &);
        };

        struct AlertState {
            static void enter(Alarmuino &);

            static void leave(Alarmuino &);
        };
    };

}

#endif //ALARMUINO_ALARMUINO_H
