//Conditionals
//Derek Y

#include <stdio.h>

int main(void)
{
    int num1 = 3;
    int num2 = 3;

    /*
    if (conditon)
    {
        condition body
    }
    */

   if (num2 < num1)
   {
        printf("%i is greater than %i \n", num1, num2);
   }
   else if (num2 > num1)
   {
        printf("%i is greater than %i \n", num2, num1);
   }
   else
   {
        printf("%i is equal to %i \n", num2, num1);
   }
}
