#ifndef TTYS_BATTERY_H
#define TTYS_BATTERY_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ttybattery {
    /* while() boolean */
    bool running;

    /* Running option */
    struct {
        bool screensaver;
        bool center;
        char format[100];
        int color;
        bool bold;
        long delay;
        bool blink;
        long nsdelay;
    } option;

    /* Battery state */
    struct {
        int charge;
        int capacity;
        int time_remaining;
        int temperature;
        char status[20];
    } state;

    /* Geometry */
    struct {
        int x, y, w, h;
        int a, b;
    } geometry;

    /* Multiple battery support */
    int num_batteries;
    struct {
        int charge;
        int capacity;
        int time_remaining;
        int temperature;
        char status[20];
        int x, y, w, h;
    } *batteries;

    /* Low battery notification */
    bool notify_low_battery;
    int low_battery_threshold;

    /* Power source notification */
    bool notify_power_source;
};

/* prototypes */
void draw_number(int n, int x, int y);
void draw_battery(int x, int y, int width, int height, int percent);
void update_hour(void);

/* Number matrix */
const bool number[][15] =
{
     {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}, /* 0 */
     {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 1 */
     {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}, /* 2 */
     {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}, /* 3 */
     {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}, /* 4 */
     {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}, /* 5 */
     {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}, /* 6 */
     {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 7 */
     {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}, /* 8 */
     {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}, /* 9 */
};

#endif // TTYS_BATTERY_H
