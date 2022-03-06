#ifndef REMOTE_CHRISMAS_TREE_LEDS_WIFICONTROLLER_H
#define REMOTE_CHRISMAS_TREE_LEDS_WIFICONTROLLER_H

#include "Arduino.h"

namespace WiFiController {
    void getWiFiSSIDFromEEPROM(char *ssid);
    void getWiFiPasswordFromEEPROM(char *password);
    void setWifiCredentials(String& ssid, String& password);
}

#endif //REMOTE_CHRISMAS_TREE_LEDS_WIFICONTROLLER_H
