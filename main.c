#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
		fflush(stdout);
        FILE *fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
        int battery_percentage;
        fscanf(fp, "%d", &battery_percentage);
        fclose(fp);

        printf("Battery percentage: %d%%", battery_percentage);
        fflush(stdout);

        sleep(1);
    }
    return 0;
}
