//interation.c
//Derek Y
//Notes for Loops


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //counting up
    int count = 10;
    // while (count < 0) //loop condition
    // {
    //     printf("%i\n", count);
    //     count++; //iterator is what is changing
    // }
    //pre-check loops
    for (int i = 10; i > -1; i--)
    {
        printf("%i\n", i);
    }

    while (count > -1)
    {
        printf("%i\n", count);
        count--;
    }

    //post check loop
    //check for what values you don't want
    int age; //must declare variable before do-while; only use to validate input
    do
    {
        age = get_int("Age: ");
        printf("You are not 21\n");
    }
    while (age < 21);
}