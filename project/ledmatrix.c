// gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
#include <bcm2835.h>
#include "ledmatrix.h"
#include <stdio.h>
#include <assert.h>
#include "textassert.h"
#include <math.h>
#include "chelsea.h"

#include <time.h>
#include <stdio.h>



int main(void)
{

    u_int8_t(*arsenal)[24][24];
    arsenal = &arsenalFC;

    u_int8_t(*chelsea)[24][24];
    chelsea = &chelseaFC;

    u_int8_t(*manchester)[24][24];
    manchester = &manchesterFc;

    u_int16_t intialized = bcm2835_init();

    assert(intialized == 1);

    intialized = setup();
    assert(intialized == 0);
    char *letter = "ABCDE01234567891";

    int msec = 0, trigger = 10; /* 10ms */
    int minutes = 0;
    int seconds = 0;
    clock_t start = clock();
    char playTime[6] = {0};

    u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH] = {0};

    char *score = "4";
    char *score2 = "6";

    addScore(score, 0, 8, matrix, font8x8_basic, 8, 8); //GET IT FROM Service
    addScore(score2, 0, 50, matrix, font8x8_basic, 8, 8); //GET it from
    //  addTime(matrix);
    while (1)
    {
        clock_t now = clock();
        clock_t difference = now - start;
        msec = difference / CLOCKS_PER_SEC;

        if (msec >= 1)
        {
            seconds += msec;

            if (seconds >= 60)
            {
                minutes += 1;
                seconds -= 60;
            }
            sprintf(playTime, "%02d:%02d", minutes, seconds);

            char *cs = playTime;
            addTime(matrix, cs, 3, 16);
            start = now;
        }

          merge(manchesterFc, 8, 0, arsenal, 8, 40, matrix);

        //drawText(letter, 0, 0, font8x8_basic, 8, 8);
     draw233(LED_PANEL_WIDTH, LED_PANEL_HEIGHT, matrix, 0, 0);
    }

    return 0;
}