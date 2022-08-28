#include <ESP8266WiFi.h>
#include "Arduino.h"
#include "EEPROM.h"

#include "constants.h"
#include "WiFiController.h"
#include "config.h"


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
    setUpConnection();
}
bool WiFiController::tryToConnectToWiFi() {
    char saved_wifi_ssid[MAX_SSID_LENGTH + 1];
    char saved_wifi_password[MAX_WIFI_PASSWORD_LENGTH + 1];

    WiFiController::getWiFiSSIDFromEEPROM(saved_wifi_ssid);
    WiFiController::getWiFiPasswordFromEEPROM(saved_wifi_password);

    // try to connect to Wi-Fi
    WiFi.mode(WIFI_STA);
    for (int i = 0; i < 3; ++i) {
        WiFi.begin(saved_wifi_ssid, saved_wifi_password);

        if (WiFi.waitForConnectResult() == WL_CONNECTED) {
            return true;
        }
        else {
            Serial.println("Error while connecting to WiFi!");
        }
        delay(3000);
    }

    return false;
}

void WiFiController::setUpConnection() {
    if (!WiFiController::tryToConnectToWiFi()) {
        delay(100);
        WiFi.mode(WIFI_AP);
        WiFi.softAP(OWN_WIFI_SSID, OWN_WIFI_PASSWORD);
    }
}
