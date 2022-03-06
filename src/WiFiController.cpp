#include "Arduino.h"
#include "EEPROM.h"

#include "constants.h"
#include "WiFiController.h"


void WiFiController::getWiFiSSIDFromEEPROM(char *ssid) {
    for (byte i = 0; i < MAX_SSID_LENGTH; ++i)
    {
        ssid[i] = char(EEPROM.read(i));
    }
    ssid[MAX_SSID_LENGTH] = 0;
}

void WiFiController::getWiFiPasswordFromEEPROM(char *password) {
    for (byte i = 0; i < MAX_WIFI_PASSWORD_LENGTH; ++i)
    {
        password[i] = char(EEPROM.read(i + MAX_SSID_LENGTH));
    }
    password[MAX_WIFI_PASSWORD_LENGTH] = 0;
}

void WiFiController::setWifiCredentials(String& ssid, String& password) {
    if (!ssid.isEmpty()) {
        byte ssidLen = ssid.length();
        if (ssid.length() > (unsigned int) MAX_SSID_LENGTH) {
            ssidLen = MAX_SSID_LENGTH;
        }

        for (byte i = 0; i < ssidLen; ++i) {
            EEPROM.write(i, ssid[i]);
        }
        for (byte i = ssidLen; i < MAX_SSID_LENGTH; ++i) {
            EEPROM.write(i, 0);
        }

        byte passLen = password.length();
        if (password.length() > (unsigned int) MAX_SSID_LENGTH) {
            passLen = MAX_SSID_LENGTH;
        }
        for (byte i = 0; i < passLen; ++i) {
            EEPROM.write(i + MAX_SSID_LENGTH, password[i]);
        }
        for (byte i = passLen; i < MAX_WIFI_PASSWORD_LENGTH; ++i) {
            EEPROM.write(i + MAX_SSID_LENGTH, 0);
        }
    }

    EEPROM.commit();
    EspClass::restart();
}
