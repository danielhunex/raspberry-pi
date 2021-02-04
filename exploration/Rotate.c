/**
 * Turn on the LEDS in rotational manner Green to Yellow to Red and repeat 
 * As per the JPL Coding Standards, we have compile this with all the warning enabled.
 * gcc -Wall -pedantic -std=iso9899:1999 -o rotate Rotate.c -l bcm2835 
 * However, it seems that the bcm2835 does not follow the JPL standard and there is an error/warning when compiling it with the above command
 * The following command does work however without the iso standard
 * gcc -Wall -pedantic -o rotate rotate.c -l bcm2835
 **/

#include <bcm2835.h>
#include <stdio.h>
#include <assert.h>

#define PINY RPI_GPIO_P1_11
#define PING RPI_GPIO_P1_07
#define PINR RPI_GPIO_P1_08

int main(int argc, char **argv)
{

  int intialized = bcm2835_init();

  assert(intialized == 1);

  // Set the pin to be an output
  bcm2835_gpio_fsel(PINY, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PING, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PINR, BCM2835_GPIO_FSEL_OUTP);

  //turn all of them to low
  bcm2835_gpio_clr(PINR);
  bcm2835_gpio_clr(PINY);
  bcm2835_gpio_clr(PING);

  /* @non-terminating@ */
  while (1)
  {

    bcm2835_gpio_clr(PINR);
    bcm2835_gpio_write(PING, HIGH);
    bcm2835_delay(500);

    bcm2835_gpio_clr(PING);
    bcm2835_gpio_write(PINY, HIGH);
    bcm2835_delay(500);

    bcm2835_gpio_clr(PINY);
    bcm2835_gpio_write(PINR, HIGH);
    bcm2835_delay(500);
  }

  int closed = bcm2835_close();

  assert(closed == 1);
  return 0;
}
