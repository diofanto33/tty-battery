#ifndef TTY_BATTERY_BATTERY_CONTROLLER_H
#define TTY_BATTERY_BATTERY_CONTROLLER_H

#include "tty_battery.h"

/* path to the battery file */
#define BATTERY_PATH "/sys/class/power_supply/BAT0"

void get_battery_state(BATTERY_STATE *state_buffer, char * battery_path, unsigned int interval);

#endif //TTY_BATTERY_BATTERY_CONTROLLER_H
