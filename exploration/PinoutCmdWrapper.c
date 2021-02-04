
/**
 * Turn on the LEDS in rotational manner Green to Yellow to Red and repeat 
 * As per the JPL Coding Standards, compile this with all the warning enabled.
 * gcc -Wall -pedantic -std=iso9899:1999 -o readallcmd ReadAllCommand.c  * 
 **/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("pinout");
    return 0;
}