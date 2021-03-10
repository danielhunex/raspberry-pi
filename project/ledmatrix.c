/**
 * Copyright 2021 Daniel Hunegnaw 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 *  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
 * */


// gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
#define _GNU_SOURCE
#include <bcm2835.h>
#include "ledmatrix.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "teams.h"
#include <time.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ISOLATED_CORE 3


//Sets the CPU affinity to core 3
//calls to bcm2835_int() to initialize
//merges various data needed to display score board
//run infinity loop to create the display

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

    addScore(score, 0, 8, matrix, font8x8_basic, 8, 8);   
    addScore(score2, 0, 50, matrix, font8x8_basic, 8, 8);

    merge(manchesterFc, 8, 0, chelseaFC, 8, 40, matrix);
                                                         

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
