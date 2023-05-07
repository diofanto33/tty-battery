
#include "battery_controller.h"

int main()
{
    BATTERY_STATE state;
    get_battery_state(&state, BATTERY_PATH, 1);

    return 0;
}
