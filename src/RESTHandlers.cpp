#include "RESTHandlers.h"
#include "ESPAsyncWebServer.h"
#include "config.h"
#include "Controller.h"

void handleControl(AsyncWebServerRequest *request) {
    if (request->hasArg(CONTROL_POWER_STATE_ARG_NAME))
    {
        String val = request->arg(CONTROL_POWER_STATE_ARG_NAME);
        Serial.println(val);
        Controller::powerOnOff(val);
    }
    else if (request->hasArg("change-mode"))
    {
        Controller::changeMode();
    }

    request->send(200);
}

void handleSetPowerState(AsyncWebServerRequest *request) {
    if (!request->hasArg(CONTROL_POWER_STATE_ARG_NAME)) {
        request->send(400);
        return;
    }

    Controller::powerOnOff(request->arg(CONTROL_POWER_STATE_ARG_NAME));

    request->send(200);
}

void handleChangeMode(AsyncWebServerRequest *request) {
    Controller::changeMode();
    request->send(200);
}
