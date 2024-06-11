// pennies.c
// Derek
// doubles pennies for each day in a month

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int days;
    do
    {
        days = get_int("Days in month: ");
    }
    while (days < 28 || days > 31);

    float pennies;
    do
    {
        pennies = get_int("Pennies on first day: ");
    }
    while (pennies < 1);

    long double total = ((pennies * pow(2, days)) / 100) - (pennies / 100);
    printf("$%.2Lf\n", total);
}