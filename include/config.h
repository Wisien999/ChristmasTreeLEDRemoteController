#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#include "Arduino.h"

#define RELAY_PIN D1 // ESP12E: GPIO5 / Pin20
#define SWITCH_BUTTON_PIN D0 // ESP12E: GPIO16 / Pin4

#define POWER_OFF LOW
#define POWER_ON HIGH

#define GET_POWER_ON_RESPONSE "ON"
#define GET_POWER_OFF_RESPONSE "OFF"

#define POWER_STATE_URL "/power"
#define CHANGE_MODE_URL "/mode"
#define GENERAL_CONTROL_URL "/control"
#define WIFI_CREDENTIALS_PAGE_URL "/wifi-credentials"
#define WIFI_CREDENTIALS_CONTROL_URL "/wifi-control"

#define CONTROL_POWER_STATE_ARG_NAME "power-state"
#define CHANGE_MODE_ARG_NAME "change-mode"
#define CONTROL_WIFI_SSID_ARG_NAME "wifi-ssid"
#define CONTROL_WIFI_PASSWORD_ARG_NAME "wifi-pass"

#define CONTROL_URL_VAR_NAME "GENERAL-CONTROL-URL"
#define TURN_OFF_ON_BUTTON_TEXT_VAR_NAME "SET-POWER-STRING"
#define TURN_Off_ON_BUTTON_VALUE_VAR_NAME "SET-POWER-VALUE"
#define CONTROL_POWER_STATE_ARG_NAME_VAR "SET-POWER-STATE-ARG-NAME"
#define POWER_STATE_INFO_VAR_NAME "POWER-STATE"
#define CHANGE_MODE_ARG_NAME_VAR_NAME "CHANGE-MODE-ARG-NAME"
#define WIFI_CREDENTIALS_CONTROL_URL_VAR_NAME "WIFI-CREDENTIALS-CONTROL-URL"
#define WIFI_PASSWORD_ARG_VAR_NAME "WIFI-PASSWORD-ARG-NAME"
#define WIFI_SSID_ARG_VAR_NAME "WIFI-SSID-ARG-NAME"


#endif