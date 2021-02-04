#include<stdio.h>
#include<string.h>

int main(void)
{
    int first ;
    int second;
    char string [10] ="250";

     &first = string;

     sscanf(string,"%d", &second);

     printf("The value of the first variable is %d \n",first);
     printf("The value of the second variable is %d \n",second);


}