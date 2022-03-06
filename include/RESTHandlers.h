#ifndef REMOTE_CHRISMAS_TREE_LEDS_RESTHANDLERS_H
#define REMOTE_CHRISMAS_TREE_LEDS_RESTHANDLERS_H

#include "ESPAsyncWebServer.h"

namespace RESTHandlers {
    void handleControl(AsyncWebServerRequest *request);
    void handleSetPowerState(AsyncWebServerRequest *request);
    void handleChangeMode(AsyncWebServerRequest *request);
    void handleSetWifiCredentials(AsyncWebServerRequest *request);
}

#endif //REMOTE_CHRISMAS_TREE_LEDS_RESTHANDLERS_H
