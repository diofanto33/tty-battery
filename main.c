#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* path to the battery file */
#define BATTERY_PATH "/sys/class/power_supply/BAT0/capacity"
#define BATTERY_STATUS_PATH "/sys/class/power_supply/BAT0/status"

int 
main() 
{
    int res;
    FILE *fp = NULL;
    char battery_status[20];
    unsigned int battery_percentage;
    while (1)
    {
        
        fp = fopen(BATTERY_PATH, "r");

        if(fp == NULL) {
            perror("Error while opening battery file");
            exit(EXIT_FAILURE);
        }

            res = fscanf(fp, "%u", &battery_percentage);
        if(res != 1)
        {
            perror("Error while reading battery percentage");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
        fp = fopen(BATTERY_STATUS_PATH, "r");
        if(fp == NULL)
        {
            perror("Error while opening battery status file");
            exit(EXIT_FAILURE);
        }

        res = fscanf(fp, "%s", battery_status);
        if(res != 1)
        {
            perror("Error while reading battery status");
            exit(EXIT_FAILURE);
        }

        fputs("\033c", stdout); // Clear the screen
        fprintf(stdout,"Battery percentage: %d%%\nBattery status: %s\n", battery_percentage, battery_status); // Print the battery percentage and status
        sleep(1);
    }
    return 0;
}
