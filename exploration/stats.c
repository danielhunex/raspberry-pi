#include <stdio.h>

int main(void)
{
    FILE *temperatureFile;
    double T;
    temperatureFile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (temperatureFile == NULL)
        ; //print some message
    fscanf(temperatureFile, "%lf", &T);
    T /= 1000;
    printf("The temperature is %6.3f C.\n", T);
    fclose(temperatureFile);
    return 0;
}