// fahrenheit.c
// Derek
// Converts C to F

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float C = get_float("What is the temperature outside? ");
    float F = ((C * 9) / 5) + 32;
    printf("%0.1f \n", F);
}