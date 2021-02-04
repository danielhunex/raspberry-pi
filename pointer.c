#include<stdio.h>

int main (void)
{
     int a = 4;
     int *ptr_to_a = &a;
     *ptr_to_a = 5;
     int x[5]={1,2,3,4,5};
 
    printf("The value of a is %d\n",a);
    printf("The value of ptr_to_a is %d\n",ptr_to_a);
    printf("The value of the variable at the ptr_t_a address is %d\n",*ptr_to_a);
   // printf("The address of the pointer variable is %d\n",&ptr_t_a);

  char ch = 'C';
   void * ptr1  = &ch;

  printf("The value of ch is %d\n", *((int*) ptr1));
  printf("The value of ch is %d\n", *((char*) ptr1));
   printf("The value of ptr is %d\n", (int*) ptr1);

    char str [5]="sixs";  
   printf("The value of the string str is %s \n",str);

   for( int i=0;i<5;i++)
   {
       printf("%d \n", x[i]);
   }

   int *ptr = x;
int count=0;
   while( count++<5)
   {
       printf   ("%d \n", *ptr);
       ptr++;
   }
 
    return 0;
}