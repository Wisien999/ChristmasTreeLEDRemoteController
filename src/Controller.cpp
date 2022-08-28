#include "config.h"
#include "Controller.h"

bool Controller::_poweredOn = false;

void Controller::powerOff() {
    digitalWrite(POWER_RELAY_PIN, POWER_OFF);
    digitalWrite(LED_BUILTIN, HIGH);
    _poweredOn = false;
}

void Controller::powerOn() {
    digitalWrite(POWER_RELAY_PIN, POWER_ON);
    digitalWrite(LED_BUILTIN, LOW);
    _poweredOn = true;
}

void Controller::powerOnOff(const String& targetState) {
    if (targetState.toInt() == 0) { powerOff(); }
    else { powerOn(); }
}


void Controller::changeMode() {
    digitalWrite(BUTTON_RELAY_PIN, HIGH);
    auto startTime = millis();
    while (millis() - startTime < 100) Serial.println("changing mode");
    digitalWrite(BUTTON_RELAY_PIN, LOW);
}

bool Controller::isPoweredOn() {
    return _poweredOn;
}
