// gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
#include <bcm2835.h>
#include <stdio.h>
#include <assert.h>
#include "textassert.h"
#include <math.h>
#include "chelsea.h"
#include "font/font8x8.h"
#include <time.h>
#include <stdio.h>

#define atoa(x) #x

#define RED_UPPER RPI_V2_GPIO_P1_29   //GPIO5
#define GREEN_UPPER RPI_V2_GPIO_P1_33 //GPIO 13
#define BLUE_UPPER RPI_V2_GPIO_P1_31  //GPIO 06

#define RED_LOWER RPI_V2_GPIO_P1_32   //GPIO 12
#define GREEN_LOWER RPI_V2_GPIO_P1_36 //GPIO 16
#define BLUE_LOWER RPI_V2_GPIO_P1_16  //GPIO 23

#define OE RPI_V2_GPIO_P1_07        //GPIO 04
#define CLK RPI_V2_GPIO_P1_11       //GPIO 17
#define LATCH RPI_V2_GPIO_P1_40     //GPIO 21
#define ADDRESS_A RPI_V2_GPIO_P1_15 //GPIO22
#define ADDRESS_B RPI_V2_GPIO_P1_37 //GPIO 26
#define ADDRESS_C RPI_V2_GPIO_P1_13 //GPIO 27
#define ADDRESS_D RPI_V2_GPIO_P1_38 //GPIO 20

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 8

#define ADDRESS_MASK 0xF

int setup(void)
{
    // Set the pin to be an output
    bcm2835_gpio_fsel(RED_UPPER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(GREEN_UPPER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(BLUE_UPPER, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_fsel(RED_LOWER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(GREEN_LOWER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(BLUE_LOWER, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_fsel(OE, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(CLK, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(LATCH, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_fsel(ADDRESS_A, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_B, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_C, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_D, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_clr(ADDRESS_A);
    bcm2835_gpio_clr(ADDRESS_B);
    bcm2835_gpio_clr(ADDRESS_C);
    bcm2835_gpio_clr(ADDRESS_D);

    bcm2835_gpio_clr(CLK);
    bcm2835_gpio_clr(LATCH);
    bcm2835_gpio_write(OE, HIGH);

    bcm2835_gpio_clr(GREEN_UPPER);
    bcm2835_gpio_clr(BLUE_UPPER);
    bcm2835_gpio_clr(RED_UPPER);

    bcm2835_gpio_clr(GREEN_LOWER);
    bcm2835_gpio_clr(BLUE_LOWER);
    bcm2835_gpio_clr(RED_LOWER);
    return 1;
}

int clockData()
{
    bcm2835_gpio_write(CLK, HIGH);
    bcm2835_gpio_write(CLK, LOW);
    return 1;
}

int selectRow(int x)
{
    bcm2835_gpio_write(ADDRESS_A, (x & ADDRESS_MASK) & (1 << 0));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_B, (x & ADDRESS_MASK) & (1 << 1));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_C, (x & ADDRESS_MASK) & (1 << 2));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_D, (x & ADDRESS_MASK) & (1 << 3));
    delayMicroseconds(5);
    return 1;
}

int latchData()
{
    bcm2835_gpio_write(LATCH, HIGH);
    bcm2835_gpio_write(LATCH, LOW);
    return 1;
}

int setPixel(u_int8_t x, u_int8_t y, u_int8_t r, u_int8_t g, u_int8_t b)
{
    if (x < 16)
    {

        bcm2835_gpio_write(RED_UPPER, r ? HIGH : LOW);
        bcm2835_gpio_write(GREEN_UPPER, g ? HIGH : LOW);
        bcm2835_gpio_write(BLUE_UPPER, b ? HIGH : LOW);
    }
    else
    {

        bcm2835_gpio_write(RED_LOWER, r ? HIGH : LOW);
        bcm2835_gpio_write(GREEN_LOWER, g ? HIGH : LOW);
        bcm2835_gpio_write(BLUE_LOWER, b ? HIGH : LOW);
    }
    clockData();

    return 1;
}

int draw3264(u_int8_t (*matrix)[32][64])
{

    for (u_int8_t i = 0; i < 16; i++)
    {

        for (u_int8_t b = 0; b < 3; b++)
        { //B2  G3 R3b
            for (u_int8_t j = 0; j < 64; j++)
            {
                u_int8_t colorUpper = (*matrix)[i][j];

                u_int8_t colorLower = (*matrix)[i + 16][j];

                bcm2835_gpio_write(RED_UPPER, colorUpper & (1 << (b + 6)) ? HIGH : LOW);
                bcm2835_gpio_write(GREEN_UPPER, colorUpper & (1 << (3 + b)) ? HIGH : LOW);

                u_int8_t blue1 = b > 1 ? 0 : colorUpper & (1 << b);
                bcm2835_gpio_write(BLUE_UPPER, blue1 ? HIGH : LOW);

                u_int8_t blue2 = b > 1 ? 0 : colorLower & (1 << b);

                bcm2835_gpio_write(RED_LOWER, colorLower & (1 << (b + 6)) ? HIGH : LOW);
                bcm2835_gpio_write(GREEN_LOWER, colorLower & (1 << (3 + b)) ? HIGH : LOW);
                bcm2835_gpio_write(BLUE_LOWER, blue2 ? HIGH : LOW);
                clockData();
            }

            bcm2835_gpio_write(OE, HIGH);

            latchData();
            selectRow(i);
            bcm2835_gpio_write(OE, LOW);
            delayMicroseconds(pow(2, b));
            bcm2835_gpio_write(OE, HIGH);
        }
    }
    return 1;
}

int draw233(u_int8_t width, u_int8_t height, u_int8_t (*matrix)[height][width], u_int8_t x, int y)
{
    //validation of inputs
    for (u_int8_t i = x; i < x + height; i++)
    {
        for (u_int8_t b = 0; b < 3; b++)
        { //RGB 332
            for (u_int8_t j = 0; j < 64; j++)
            {
                u_int16_t colorUpper = 0;
                u_int16_t colorLower = 0;
                u_int8_t blue1 = 0;
                u_int8_t green1 = 0;
                u_int8_t red1 = 0;

                u_int8_t blue2 = 0;
                u_int8_t green2 = 0;
                u_int8_t red2 = 0;

                if (j - y < width)
                {

                    colorLower = (*matrix)[i - x][j - y];
                    colorUpper = (*matrix)[i - x][j - y];

                    blue1 = b > 2 ? 0 : colorUpper & (1 << b);
                    green1 = colorUpper & (1 << (b + 2));
                    red1 = colorUpper & (1 << (b + 5));

                    blue2 = b > 4 ? 0 : colorLower & (1 << (b));
                    green2 = colorLower & (1 << (b + 3));
                    red2 = colorLower & (1 << (b + 6));
                }

                if (i < 16)
                {
                    bcm2835_gpio_write(RED_UPPER, red1 ? HIGH : LOW);
                    bcm2835_gpio_write(GREEN_UPPER, green1 ? HIGH : LOW);
                    bcm2835_gpio_write(BLUE_UPPER, blue1 ? HIGH : LOW);
                }
                else
                {
                    bcm2835_gpio_write(RED_LOWER, red2 ? HIGH : LOW);
                    bcm2835_gpio_write(GREEN_LOWER, green2 ? HIGH : LOW);
                    bcm2835_gpio_write(BLUE_LOWER, blue2 ? HIGH : LOW);
                }
                clockData();
            }

            bcm2835_gpio_write(OE, HIGH);

            latchData();
            selectRow(i);
            bcm2835_gpio_write(OE, LOW);
            delayMicroseconds(pow(2, b));
            // bcm2835_gpio_write(OE, HIGH);
        }
    }
    return 1;
}

int drawChar(char c, u_int8_t row, u_int8_t column)
{
    u_int8_t charIndex = c;

    const u_int8_t *chr = font8x8_basic[charIndex];

    for (u_int8_t i = row; i < row + CHAR_HEIGHT; i++)
    {
        for (u_int8_t j = 0; j < 64; j++)
        {

            //initially set all them to zero , to account for those outside of the char drawing area
            u_int8_t r = 0;
            u_int8_t b = 0;
            u_int8_t g = 0;

            if ((j - column) < CHAR_WIDTH)
            {
                r = chr[i - row] & 1 << (j - column);
                b = chr[i - row] & 1 << (j - column);
                g = chr[i - row] & 1 << (j - column);
            }

            if (i < 16)
            {
                bcm2835_gpio_write(RED_UPPER, r ? HIGH : LOW);
                bcm2835_gpio_write(GREEN_UPPER, g ? HIGH : LOW);
                bcm2835_gpio_write(BLUE_UPPER, b ? HIGH : LOW);
            }
            else
            {

                bcm2835_gpio_write(RED_LOWER, r ? HIGH : LOW);
                bcm2835_gpio_write(GREEN_LOWER, g ? HIGH : LOW);
                bcm2835_gpio_write(BLUE_LOWER, b ? HIGH : LOW);
            }
            clockData();
        }
        bcm2835_gpio_write(OE, HIGH);
        latchData();
        selectRow(i);
        bcm2835_gpio_write(OE, LOW);
    }
    return 1;
}

int drawText(const char *str, u_int8_t x, u_int8_t y)
{
    while (*str)
    {
        if (y >= 64)
        {
            y = 0;
            x += CHAR_HEIGHT + 1;
        }
        drawChar(*str++, x, y);
        y += CHAR_WIDTH;
    }
    return 1;
}

int addScore(char *score1, u_int8_t startX, u_int8_t startY, u_int8_t matrix[32][64])
{
    char *str = score1;
    u_int8_t x = startX;
    u_int8_t y = startY;
    while (*str)
    {
        char c = *str++;
        u_int8_t charIndex = c;
        const u_int8_t *chr = font8x8_basic[charIndex];

        for (int i = x; i < x + CHAR_HEIGHT; i++)
        {
            for (int j = y; j < y + CHAR_WIDTH; j++)
            {
                matrix[i][j] = (chr[i-x] & (1 << (j - y))) ? 255 : 0;
            }
        }
        y += CHAR_WIDTH;
    }

    return 1;
}

int addTime(u_int8_t matrix[32][64])
{
    //time_t now = time(NULL);
    // struct tm *tm_struct = localtime(&now);

    // int hour = tm_struct->tm_hour;
    // int minute = tm_struct->tm_min;

    // char *string = atoa(hour) + ":" + atoa(minute);
    // addScore(string, 2, 24, matrix);

    addScore("8:1", 2, 24, matrix);

    return 1;
}

int merge(u_int8_t matrix1[24][24], u_int8_t x1, u_int8_t y1, u_int8_t matrix2[24][24], u_int8_t x2, u_int8_t y2, u_int8_t matrix[32][64])
{

    //TODO: optimize this to do in one loop (with row and column counter)
    for (u_int8_t i = x1; i < 24 + x1; i++)
    {
        for (u_int8_t j = y1; j < 24 + y1; j++)
        {
            matrix[i][j] = matrix1[i - x1][j - y1];
        }
    }

    for (u_int8_t i = x2; i < 24 + x2; i++)
    {
        for (u_int8_t j = y2; j < 24 + y2; j++)
        {
            matrix[i][j] = matrix2[i - x2][j - y2];
        }
    }

    return 1;
}

int main(void)
{

    u_int8_t(*chelsea)[24][24];
    chelsea = &chelseaFC;

    u_int8_t(*manchester)[24][24];
    manchester = &manchesterFc;

    u_int8_t(*liverpool)[24][24];
    liverpool = &liverpoolFc;

    u_int16_t intialized = bcm2835_init();

    assert(intialized == 1);

    intialized = setup();
    assert(intialized == 1);
    char *letter = "I love you mare! 0-1";

    u_int8_t matrix[32][64] = {0};

    char *score = "4";
    char *score2 = "6";

    addScore(score, 0, 8, matrix);
    addScore(score2, 0, 48, matrix);
    addTime(matrix);
    while (1)
    {
        merge(manchesterFc, 8, 0, chelseaFC, 8, 40, matrix);

        // drawText(letter, 2, 3);
        draw233(64, 32, matrix, 0, 0);
    }

    return 0;
}