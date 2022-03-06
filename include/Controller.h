#ifndef REMOTE_CHRISMAS_TREE_LEDS_CONTROLLER_H
#define REMOTE_CHRISMAS_TREE_LEDS_CONTROLLER_H

#include <WString.h>

class Controller {
public:
    static void powerOff();
    static void powerOn();
    static void powerOnOff(const String& targetState);
    static void changeMode();

    static bool isPoweredOn();

protected:
    static bool _poweredOn;
};


#endif //REMOTE_CHRISMAS_TREE_LEDS_CONTROLLER_H
