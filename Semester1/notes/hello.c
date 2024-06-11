// hello.c
// Derek Yee
// Prints Hello

#include <stdio.h> //add printf function
#include <cs50.h> //add cs50 functions

//green flag click - "entry block"
int main(void)
{
    // printf("hello \n");

    // string fName = get_string("What's your first name? ");
    // string lName = get_string("What's your last name? ");
    // printf("hello %s %s\n", fName, lName);

    // int number = get_int("Enter a number: ");

    // //shortened versions
    // number *= 2;
    // number -= 2;
    // number += 2;
    // number /= number 2;

    // number = number % 2; //mod 2, finds the remainder
    // number %= 2;

    // number++; //adds 1
    // number--; //subtract 1

    // printf("Your number multiplied by 2 is %i\n", number);

    int a = 5;
    int b = 2;
    float c = 2.0;

    printf("%i / %i = %.2f \n", a,b,(float)a/b);

    //%.2f makes only 2 decimal places

}