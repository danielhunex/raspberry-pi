#include <bcm2835.h>
#include <stdio.h>
#include <assert.h>

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
//#define ADDRESS_E RPI_V2_GPIO_P1_18 //GPIO 24

int setup(void)
{
    // Set the pin to be an output
    bcm2835_gpio_fsel(RED_UPPER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(GREEN_UPPER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(BLUE_UPPER, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(OE, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(CLK, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(LATCH, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_A, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_B, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_C, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ADDRESS_D, BCM2835_GPIO_FSEL_OUTP);
   // bcm2835_gpio_fsel(ADDRESS_E, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_clr(ADDRESS_A);
    bcm2835_gpio_clr(ADDRESS_B);
    bcm2835_gpio_clr(ADDRESS_C);
    bcm2835_gpio_clr(ADDRESS_D);
   // bcm2835_gpio_clr(ADDRESS_E);

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

int clock()
{
    bcm2835_gpio_write(CLK, HIGH);
    bcm2835_gpio_write(CLK, LOW);
    return 1;
}

int main(void)
{
    u_int8_t matrix[16][64] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 2, 6, 4, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    u_int16_t intialized = bcm2835_init();

    assert(intialized == 1);

    intialized = setup();
    assert(intialized == 1);
    // printf("Something soemthing,%d \n",1);
//110 4+2
    // printf("index: %d \n", matrix[15][63]);

    while (1)
    {
        u_int8_t i = 0;

        for (; i < 16; i++)
        {
            // bcm2835_gpio_write(OL, HIGH);
            for (u_int16_t j = 0; j < 64; j++)
            {

                u_int8_t color = matrix[i % 16][j];

              
                if (i <= 15)
                {
                    bcm2835_gpio_write(RED_UPPER, color & (1 << 2) ? HIGH : LOW);
                    bcm2835_gpio_write(GREEN_UPPER, color & (1 << 1) ? HIGH : LOW);
                    bcm2835_gpio_write(BLUE_UPPER, color & (1 << 0) ? HIGH : LOW);
                }
                else
                {
                    bcm2835_gpio_write(RED_LOWER, color & (1 << 0) ? HIGH : LOW);
                    bcm2835_gpio_write(GREEN_LOWER, color & (1 << 1) ? HIGH : LOW);
                    bcm2835_gpio_write(BLUE_LOWER, color & (1 << 2) ? HIGH : LOW);
                }

                clock();
            }
        
            bcm2835_gpio_write(OE, HIGH);
         
            bcm2835_gpio_write(ADDRESS_A, i & (1 << 3) ? HIGH : LOW);
            bcm2835_gpio_write(ADDRESS_B, i & (1 << 2) ? HIGH : LOW);
            bcm2835_gpio_write(ADDRESS_C, i & (1 << 1) ? HIGH : LOW);
            bcm2835_gpio_write(ADDRESS_D, i & (1 << 0) ? HIGH : LOW);

            bcm2835_gpio_write(LATCH, HIGH);
            bcm2835_gpio_write(LATCH, LOW);
            bcm2835_gpio_write(OE, LOW);
           
        }
    }

    return 0;
}