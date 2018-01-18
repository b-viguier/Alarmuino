BOARD_TAG    = uno

# recursive wildcard function, call with params:
#  - start directory (finished with /) or empty string for current dir
#  - glob pattern
# (taken from http://blog.jgc.org/2011/07/gnu-make-recursive-wildcard-function.html)
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# Override sources detection to include subdirectories
LOCAL_CPP_SRCS = $(call rwildcard,src/Arch/avr/,*.cpp) $(call rwildcard,src/App/,*.cpp) $(call rwildcard,src/Core/,*.cpp) $(call rwildcard,src/Ui/,*.cpp) $(call rwildcard,src/Utils/,*.cpp)

# Include local headers
CPPFLAGS += -I./src

# Use recent version of avr-g++ (OSX Path)
AVR_TOOLS_DIR = /usr/local

# To use arduino-IDE avrdude
AVRDUDE = /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude
AVRDUDE_CONF = /Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf

# Prevent auto-magic libs detection with Regexp (conflict with local Keyboard.h)
ARDUINO_LIBS = LiquidCrystal

include /usr/local/opt/arduino-mk/Arduino.mk
