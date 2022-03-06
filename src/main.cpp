#include <Arduino.h>
#include <LittleFS.h>
#include "ESP8266WiFi.h"
#include <ESPAsyncWebServer.h>

#include "config.h"
#include "credentials.h"
#include "Controller.h"
#include "RESTHandlers.h"


AsyncWebServer server(80);


String processor(const String &var) {
    Serial.println(var);
    if (var == POWER_STATE_INFO_VAR_NAME) {
        return Controller::isPoweredOn() ? "ON" : "OFF";
    }
    else if (var == TURN_Off_ON_BUTTON_VALUE_VAR_NAME) {
        return Controller::isPoweredOn() ? String("0") : String("1");
    }
    else if (var == TURN_OFF_ON_BUTTON_TEXT_VAR_NAME) {
        return Controller::isPoweredOn() ? String("Turn off") : String("Turn on");
    }
    else if (var == CONTROL_URL_VAR_NAME) {
        return {GENERAL_CONTROL_URL};
    }

    return {};
}


[[maybe_unused]] void setup() {
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    if (!LittleFS.begin()) {
        Serial.println("Error while mounting filesystem!");
        EspClass::restart();
        return;
    }

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(SWITCH_BUTTON_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.print("Error while connecting to WiFi!");
        EspClass::restart();
        return;
    }

    // ensure the power is off by default
    Controller::powerOff();

    // Set endpoints
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/index.html", "text/html", false, processor);
    });
    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/style.css", "text/css");
    });
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/script.js", "application/javascript");
    });
    server.on(GENERAL_CONTROL_URL, HTTP_GET, handleControl);
    server.on(POWER_STATE_URL, HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/plain",
                          Controller::isPoweredOn() ? GET_POWER_ON_RESPONSE : GET_POWER_OFF_RESPONSE);
    });
    server.on(POWER_STATE_URL, HTTP_POST, handleSetPowerState);
    server.on(CHANGE_MODE_URL, HTTP_ANY, handleChangeMode);

    // start the web server
    server.begin();


    delay(10);
    Serial.println(WiFi.localIP());
}

void loop() {
}