#include <Arduino.h>
#include <LittleFS.h>
#include "ESP8266WiFi.h"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "config.h"
#include "credentials.h"



AsyncWebServer server(80);
bool poweredOn = false;

void powerOff() {
    digitalWrite(RELAY_PIN, POWER_OFF);
    digitalWrite(LED_BUILTIN, POWER_OFF);
    poweredOn = false;
}

void powerOn() {
    digitalWrite(RELAY_PIN, POWER_ON);
    digitalWrite(LED_BUILTIN, POWER_ON);
    poweredOn = true;
}

void changeMode() {
    digitalWrite(SWITCH_BUTTON_PIN, HIGH);
    delay(100);
    digitalWrite(SWITCH_BUTTON_PIN, LOW);
}

void handleControl(AsyncWebServerRequest *request) {
    if (request->hasArg("power"))
    {
        uint8_t val = request->arg("power").toInt();
        Serial.println(val);
        if (val == 0) { powerOff(); }
        else { powerOn(); }
    }
    else if (request->hasArg("changeMode"))
    {
        changeMode();
    }

    request->send(200);
}

void handleSetPowerState(AsyncWebServerRequest *request) {
    if (!request->hasArg(SET_POWER_STATE_ARG_NAME)) {
        request->send(400);
        return;
    }

    if (request->arg(SET_POWER_STATE_ARG_NAME).toInt() == 0) { powerOff(); }
    else { powerOn(); }

    request->send(200);
}

void handleChangeMode(AsyncWebServerRequest *request) {
    changeMode();
    request->send(200);
}


String processor(const String &var) {
    Serial.println(var);
    if (var == "POWER-STATE") {
        return poweredOn ? "ON" : "OFF";
    }
    else if (var == "SET-POWER-VALUE") {
        if (poweredOn) {
            return {"0"};
        }
        else {
            return {"1"};
        }
    }
    else if (var == "SET-POWER-STRING") {
        if (poweredOn) {
            return {"Turn off"};
        }
        else {
            return {"Turn on"};
        }
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

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/index.html", "text/html", false, processor);
    });
    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/style.css", "text/css");
    });
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/script.js", "application/javascript");
    });
    server.on("/control", HTTP_GET, handleControl);
    server.on(GET_POWER_STATE_URL, HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/plain", poweredOn ? GET_POWER_ON_RESPONSE : GET_POWER_OFF_RESPONSE);
    });
    server.on(SET_POWER_STATE_URL, HTTP_PATCH, handleSetPowerState);
    server.on(CHANGE_MODE_URL, HTTP_ANY, handleChangeMode);

    server.begin();


    delay(10);
    Serial.println(WiFi.localIP());
}

void loop() {
}