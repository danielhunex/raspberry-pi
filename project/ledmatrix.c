// gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
#include <bcm2835.h>
#include "ledmatrix.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "chelsea.h"
#include <time.h>
#include <stdio.h>

int main(void)
{

    u_int16_t intialized = bcm2835_init();

    assert(intialized == 1);

    intialized = setup();
    assert(intialized == 0);

    u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH] = {0};

    char *score = "4";
    char *score2 = "6";

    addScore(score, 0, 8, matrix, font8x8_basic, 8, 8);   //GET IT FROM Service
    addScore(score2, 0, 50, matrix, font8x8_basic, 8, 8); //GET it from service

    merge(manchesterFc, 8, 0, chelseaFC, 8, 40, matrix); //bring the data from API

    int minutes = 0;
    int seconds = 0;
    char playTime[6] = {0};
    time_t start;
    time_t stop;
    start = time(NULL);
    stop = start;

    while (1)
    {
        start = time(NULL);

        if (start == stop || start - stop >= 1)
        {
            seconds += start - stop;

            if (seconds >= 60)
            {
                minutes += 1;
                seconds -= 60;
            }
            sprintf(playTime, "%02d:%02d", minutes, seconds);

            char *cs = playTime;
            addTime(matrix, cs, 3, 16);
            stop = start;
        }

        draw233(LED_PANEL_WIDTH, LED_PANEL_HEIGHT, matrix, 0, 0);
    }

    return 0;
}
