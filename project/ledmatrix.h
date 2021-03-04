#include <stdio.h>
#include <bcm2835.h>
#include <math.h>
#include <assert.h>
#include "font/font8x8.h"
#include "font/font6x5.h"

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

#define ADDRESS_MASK 0xF

#define LED_PANEL_WIDTH 64
#define LED_PANEL_HEIGHT 32
#define SCAN_HEIGHT 16

#define LOGO_HEIGHT 24
#define LOGO_WIDTH 24

#define SOCCER_BALL_HEIGHT 11
#define SOCCER_BALL_WIDTH 11

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

    //clear the addresses
    bcm2835_gpio_clr(ADDRESS_A);
    bcm2835_gpio_clr(ADDRESS_B);
    bcm2835_gpio_clr(ADDRESS_C);
    bcm2835_gpio_clr(ADDRESS_D);

    //clear clock
    bcm2835_gpio_clr(CLK);

    //clear latch
    bcm2835_gpio_clr(LATCH);

    //disable the OE
    bcm2835_gpio_write(OE, HIGH);

    //turn off (LOW) all the upper half color control GPIOs
    bcm2835_gpio_clr(GREEN_UPPER);
    bcm2835_gpio_clr(BLUE_UPPER);
    bcm2835_gpio_clr(RED_UPPER);

    //turn off (LOW) all the lower half color control GPIOs
    bcm2835_gpio_clr(GREEN_LOWER);
    bcm2835_gpio_clr(BLUE_LOWER);
    bcm2835_gpio_clr(RED_LOWER);
    return 0;
}

int clockData(void)
{
    bcm2835_gpio_write(CLK, HIGH);
    bcm2835_gpio_write(CLK, LOW);
    return 0;
}

int selectRow(int x)
{
    assert(x >= 0 && x <= 31);
    bcm2835_gpio_write(ADDRESS_A, (x & ADDRESS_MASK) & (1 << 0));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_B, (x & ADDRESS_MASK) & (1 << 1));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_C, (x & ADDRESS_MASK) & (1 << 2));
    delayMicroseconds(5);
    bcm2835_gpio_write(ADDRESS_D, (x & ADDRESS_MASK) & (1 << 3));
    delayMicroseconds(5);
    return 0;
}

int latchData(void)
{
    bcm2835_gpio_write(LATCH, HIGH);
    bcm2835_gpio_write(LATCH, LOW);
    return 0;
}

int drawChar(char c, u_int8_t row, u_int8_t column, unsigned char font[128][8], u_int8_t charWidth, u_int8_t charHeight)
{
    assert(row >= 0 && charHeight > 0 && charHeight <= 8);
    assert((row + charHeight) <= 32);

    assert(column >= 0 && charWidth > 0 && charWidth <= 8);
    assert(column < 64);

    u_int8_t charIndex = c;
    const u_int8_t *chr = font[charIndex];

    for (u_int8_t i = row; i < row + charHeight; i++)
    {
        for (u_int8_t j = 0; j < LED_PANEL_WIDTH; j++)
        {

            //initially set all them to zero , to account for those outside of the char drawing area
            u_int8_t r = 0;
            u_int8_t b = 0;
            u_int8_t g = 0;

            if ((j - column) < charWidth)
            {
                r = chr[i - row] & (1 << (j - column));
                b = chr[i - row] & (1 << (j - column));
                g = chr[i - row] & (1 << (j - column));
            }

            if (i < SCAN_HEIGHT)
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
    return 0;
}

int draw233(u_int8_t width, u_int8_t height, u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH], u_int8_t x, int y)
{

    assert(x >= 0 && height >= 0 && height <= 32);
    assert(y < 64 && y >= 0);

    for (u_int8_t i = x; i < x + height; i++)
    {
        for (u_int8_t b = 0; b < 3; b++)
        { //RGB 332
            for (u_int8_t j = 0; j < LED_PANEL_WIDTH; j++)
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

                    colorLower = matrix[i - x][j - y];
                    colorUpper = matrix[i - x][j - y];

                    blue1 = b == 0 ? 0 : colorUpper & (1 << (b - 1));
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
            delayMicroseconds(5 * pow(2, b));
            bcm2835_gpio_write(OE, HIGH);
        }
    }
    return 0;
}

int drawText(const char *str, u_int8_t x, u_int8_t y, unsigned char font[128][8], u_int8_t charWidth, u_int8_t charHeight)
{
    assert(x >= 0 && y >= 0);
    assert(x <= 32 && y <= 64);

    assert(charWidth > 0 && charWidth <= 8);
    assert(charHeight > 0 && charHeight <= 8);

    while (*str)
    {
        if (LED_PANEL_WIDTH - y < charWidth)
        {
            y = 0;
            x += charHeight + 1;
        }
        drawChar(*str++, x, y, font, charHeight, charWidth);
        y += charWidth;
    }

    return 1;
}

int addScore(char *score1,
             u_int8_t startX,
             u_int8_t startY,
             u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH],
             const unsigned char font[128][8],
             u_int8_t charWidth,
             u_int8_t charHeight

)
{

    assert(startX >= 0 && startY >= 0);
    assert(startX < 32 && startY < 64);

    assert(charWidth > 0 && charWidth <= 8);
    assert(charHeight > 0 && charHeight <= 8);

    char *str = score1;
    u_int8_t x = startX;
    u_int8_t y = startY;
    while (*str)
    {
        char c = *str++;
        u_int8_t charIndex = c;
        const u_int8_t *chr = font[charIndex];

        for (int i = x; i < x + charHeight; i++)
        {
            for (int j = y; j < y + charWidth; j++)
            {
                matrix[i][j] = (chr[i - x] & (1 << (j - y))) ? 255 : 0;
            }
        }
        y += charWidth;
    }

    return 0;
}

int addTime(u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH], char *time, u_int8_t x, u_int8_t y)
{
    assert(x >= 0 && y >= 0);
    assert(x < 32 && y < 64);

    addScore(time, x, y, matrix, smallFont, 6, 5);
    return 0;
}

int merge(u_int8_t matrix1[LOGO_HEIGHT][LOGO_WIDTH],
          u_int8_t x1,
          u_int8_t y1,
          u_int8_t matrix2[LOGO_HEIGHT][LOGO_WIDTH],
          u_int8_t x2,
          u_int8_t y2,
          u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH])
{

    assert(x1 >= 0 && x1 < 32);
    assert(y1 >= 0 && y1 < 64);

    assert(x2 >= 0 && x2 < 32);
    assert(y2 >= 0 && y2 < 64);

    for (u_int8_t i = x1; i < LOGO_HEIGHT + x1; i++)
    {
        for (u_int8_t j = y1; j < LOGO_WIDTH + y1; j++)
        {
            matrix[i][j] = matrix1[i - x1][j - y1];
        }
    }

    for (u_int8_t i = x2; i < LOGO_HEIGHT + x2; i++)
    {
        for (u_int8_t j = y2; j < LOGO_WIDTH + y2; j++)
        {
            matrix[i][j] = matrix2[i - x2][j - y2];
        }
    }

    return 1;
}

int draw(int height, int width, u_int8_t matrix1[height][width],
         u_int8_t x,
         u_int8_t y,
         u_int8_t matrix[LED_PANEL_HEIGHT][LED_PANEL_WIDTH])
{

    assert(x >= 0 && x < 32);
    assert(y >= 0 && y < 64);

    assert(height > 0 && height <= 32);
    assert(width > 0 && width <= 64);

    for (u_int8_t i = x; i < height + x; i++)
    {
        for (u_int8_t j = y; j < width + y; j++)
        {
            matrix[i][j] = matrix1[i - x][j - y];
        }
    }

    return 1;
}
