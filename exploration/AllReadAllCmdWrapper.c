
/**
 * Executes the command 'gpio allreadall' from C
 * As per the JPL Coding Standards, compile this with all the warning enabled.
 * gcc -Wall -pedantic -std=iso9899:1999 -o allreadallcmd AllReadAllCmdWrapper.c
 **/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("gpio allreadall");
    return 0;
}