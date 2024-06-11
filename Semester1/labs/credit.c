#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for credit card #
    long credit = get_long("Credit Card #: ");
    int total;
    int timesTwo;
    bool valid = false;
    long number = 0;
    number = number + credit;
    number /= 10;
    // multiplies every other number by 2 and adds to "total"
    for (int i = 0; number > 0; number /= 100)
    {
        timesTwo = (2 * (number % 10));

        for (int j = 0; timesTwo > 0; timesTwo /= 10)
        {
            total = total + (timesTwo % 10);
        }
    }
    // resets number variable
    number = 0;
    number = number + credit;
    // adds all remaining digits to "total"
    for (int i = 0; number > 0; number /= 100)
    {
        total = total + (number % 10);
    }
    // check if last digit is 0
    if (total % 10 == 0)
    {
        valid = true;
    }
    printf("%i", total);
    // resets number variable
    number = 0;
    number = number + credit;
    // counts number of digits
    int digits = 0;
    for (int i = 0; number > 0; i++)
    {
        number = number / 10;
        digits += 1;
    }
    // checks what type of card it is
    if (digits == 16 && valid == true)
    {
        if (credit / 1000000000000000 % 10 == 4)
        {
            printf("VISA\n");
        }
        else if (credit / 100000000000000 % 100 > 50 && credit / 100000000000000 % 100 < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 13 && valid == true)
    {
        if (credit / 1000000000000 % 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 15 && valid == true)
    {
        if (credit / 10000000000000 % 100 == 34 || credit / 10000000000000 == 37 % 100)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
