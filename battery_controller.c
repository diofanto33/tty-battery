//
// Created by cnemo on 07/05/23.
//

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "battery_controller.h"


bool stop_signal = FALSE;

void get_battery_state(BATTERY_STATE *state_buffer, char * battery_path, unsigned int interval){

    /* Checking values */
    interval = (interval == 0) ? 1 : interval;
    if (battery_path == NULL) {
        perror("Invalid battery path.");
    }

    /* Opening files */
    unsigned int path_len = strlen(battery_path);
    char p_filepath[path_len + 9];
    char s_filepath[path_len + 7];
    char f_filepath[path_len + 12];
    char l_filepath[path_len + 16];
    strcpy(p_filepath, battery_path);
    strcpy(s_filepath, battery_path);
    strcpy(f_filepath, battery_path);
    strcpy(l_filepath, battery_path);
    strcat(p_filepath, "/capacity");
    strcat(s_filepath, "/status");
    strcat(f_filepath, "/charge_full");
    strcat(l_filepath, "/capacity_level");

    FILE * full_file = fopen(f_filepath, "r");
    if (full_file != NULL) {
        fscanf(full_file, "%u", &(state_buffer->capacity));
        fclose(full_file);
    }



    while (!stop_signal)
    {
        FILE * percentage_file = fopen(p_filepath, "r");
        FILE * status_file = fopen(s_filepath, "r");
        FILE * level_file = fopen(l_filepath, "r");

        if (percentage_file == NULL || status_file == NULL || level_file == NULL) {
            perror("Error while opening battery file");
            exit(EXIT_FAILURE);
        }

        /* Reading percentage of battery */
        int p_scan = fscanf(percentage_file, "%u", &(state_buffer->charge));
        if (p_scan != 1) {
            perror("Error while reading battery percentage");
            exit(EXIT_FAILURE);
        }

        /* Reading status of battery */
        int s_scan = fscanf(status_file, "%s", (state_buffer->status));
        if (s_scan != 1) {
            perror("Error while reading battery status");
            exit(EXIT_FAILURE);
        }

        /* Reading level of battery */
        char level[20];
        int l_scan = fscanf(level_file, "%s", level);
        if (l_scan != 1) {
            perror("Error while reading battery level");
            exit(EXIT_FAILURE);
        }
        if (strcmp(level, "Full")){
            state_buffer->level_status = BATTERY_FULL;
        } else if (strcmp(level, "High")){
            state_buffer->level_status = BATTERY_HIGH;
        } else if (strcmp(level, "Normal")){
            state_buffer->level_status = BATTERY_NORMAL;
        } else if (strcmp(level, "Low")){
            state_buffer->level_status = BATTERY_LOW;
        } else if (strcmp(level, "Critical")){
            state_buffer->level_status = BATTERY_CRITICAL;
        } else {
            state_buffer->level_status = BATTERY_UNKNOWN;
        }

        /* Copying status to state_buffer */
        fputs("\033c", stdout); // Clear the screen
        fprintf(stdout,"Battery percentage: %d%%\nBattery status: %s\nLevel: %s\n", state_buffer->charge, state_buffer->status, level); // Print the battery percentage and status

        fclose(percentage_file);
        fclose(status_file);
        fclose(level_file);

        sleep(interval);
    }
}