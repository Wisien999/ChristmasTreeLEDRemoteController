#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#define RELAY_PIN D1 // ESP12E: GPIO5 / Pin20
#define SWITCH_BUTTON_PIN D0 // ESP12E: GPIO16 / Pin4

#define POWER_OFF LOW
#define POWER_ON HIGH

#define GET_POWER_ON_RESPONSE "ON"
#define GET_POWER_OFF_RESPONSE "OFF"

#define GET_POWER_STATE_URL "power"
#define SET_POWER_STATE_URL "power"
#define CHANGE_MODE_URL "mode"

#define SET_POWER_STATE_ARG_NAME "state"

#endif