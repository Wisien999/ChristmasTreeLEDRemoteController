#include "config.h"
#include "Controller.h"

bool Controller::_poweredOn = false;

void Controller::powerOff() {
    digitalWrite(RELAY_PIN, POWER_OFF);
    digitalWrite(LED_BUILTIN, POWER_OFF);
    _poweredOn = false;
}

void Controller::powerOn() {
    digitalWrite(RELAY_PIN, POWER_ON);
    digitalWrite(LED_BUILTIN, POWER_ON);
    _poweredOn = true;
}

void Controller::powerOnOff(const String& targetState) {
    if (targetState.toInt() == 0) { powerOff(); }
    else { powerOn(); }
}


void Controller::changeMode() {
    digitalWrite(SWITCH_BUTTON_PIN, HIGH);
    delay(100);
    digitalWrite(SWITCH_BUTTON_PIN, LOW);
}

bool Controller::isPoweredOn() {
    return _poweredOn;
}
