//functions

#include <cs50.h>
#include <stdio.h>

// defines a constant, always put in ALL CAPS
#define MAX_HEIGHT 8

// define function prototype BEFORE main (signature)
int add(int n1, int n2);

int main(void)
{
    int number_1 = get_int("Number: ");
    int number_2 = get_int("Number: ");

    int answer = add(number_1, number_2);
}

// define function definition after main

void add(int n1 , int n2) {
    int result = n1 + n2;

    printf("%i\n", result);

    // return automatically exits function
    return result;
}
