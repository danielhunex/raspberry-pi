// gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
#define _GNU_SOURCE
#include <bcm2835.h>
#include "ledmatrix.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "chelsea.h"
#include <time.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ISOLATED_CORE 3

int main(void)
{

    cpu_set_t set;

    CPU_ZERO(&set);
    CPU_SET(ISOLATED_CORE, &set);

    if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1)
    {
        printf("Unable to get an isolated core");
    };
    printf("sched_getcpu = %d\n", sched_getcpu());

    u_int16_t intialized = bcm2835_init();

    assert(intialized == 1);

    intialized = setup();
    assert(intialized == 0);

    u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH] = {0};

    char *score = "0";
    char *score2 = "1";

    addScore(score, 0, 8, matrix, font8x8_basic, 8, 8);   //GET IT FROM Service
    addScore(score2, 0, 50, matrix, font8x8_basic, 8, 8); //GET it from service

    merge(manchesterFc, 8, 0, chelseaFC, 8, 40, matrix); //bring the data from API
                                                         //   draw(32, 46, UW, 0, 8, matrix);

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
            addTime(matrix, cs, 4, 16);
            stop = start;
        }

        draw233(LED_PANEL_WIDTH, LED_PANEL_HEIGHT, matrix, 0, 0);
    }

    return 0;
}
