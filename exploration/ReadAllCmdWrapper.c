
/**
 * Executes the command 'gpio readall' from C
 * As per the JPL Coding Standards, compile this with all the warning enabled.
 * gcc -Wall -pedantic -std=iso9899:1999 -o readallcmd ReadAllCmdWrapper.c
 **/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("gpio readall");
    return 0;
}