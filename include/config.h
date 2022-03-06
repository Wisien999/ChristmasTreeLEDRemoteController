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

#define CONTROL_POWER_STATE_ARG_NAME "power-state"

#define CONTROL_URL_VAR_NAME "CONTROL-URL"
#define TURN_OFF_ON_BUTTON_TEXT_VAR_NAME "SET-POWER-STRING"
#define TURN_Off_ON_BUTTON_VALUE_VAR_NAME "SET-POWER-VALUE"
#define POWER_STATE_INFO_VAR_NAME "POWER-STATE"

#endif