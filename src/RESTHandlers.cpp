#include "RESTHandlers.h"
#include "ESPAsyncWebServer.h"
#include "config.h"
#include "Controller.h"
#include "WiFiController.h"

void RESTHandlers::handleControl(AsyncWebServerRequest *request) {
    if (request->hasArg(CONTROL_POWER_STATE_ARG_NAME))
    {
        String val = request->arg(CONTROL_POWER_STATE_ARG_NAME);
        Controller::powerOnOff(val);
    }
    else if (request->hasArg(CHANGE_MODE_ARG_NAME))
    {
        Controller::changeMode();
    }

    request->send(200);
}

void RESTHandlers::handleSetPowerState(AsyncWebServerRequest *request) {
    if (!request->hasArg(CONTROL_POWER_STATE_ARG_NAME)) {
        request->send(400);
        return;
    }

    Controller::powerOnOff(request->arg(CONTROL_POWER_STATE_ARG_NAME));

    request->send(200);
}

void RESTHandlers::handleChangeMode(AsyncWebServerRequest *request) {
    Controller::changeMode();
    request->send(200);
}

void RESTHandlers::handleSetWifiCredentials(AsyncWebServerRequest *request) {
    String ssid = {};
    String pass = {};
    if (request->hasArg(CONTROL_WIFI_SSID_ARG_NAME)) {
        ssid = request->arg(CONTROL_WIFI_SSID_ARG_NAME);
    }
    if (request->hasArg(CONTROL_WIFI_PASSWORD_ARG_NAME)) {
        pass = request->arg(CONTROL_WIFI_PASSWORD_ARG_NAME);
    }

    WiFiController::setWifiCredentials(ssid, pass);

    request->send(200);
}
