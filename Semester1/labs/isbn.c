// ISBN.c
// Derek
// checks for valid ISBN

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long ISBN;
    do
    {
        ISBN = get_long("ISBN: ");
    }
    while (ISBN <= 0 || ISBN > 10000000000);
    int total;
    for (int i = 10; i > 0; i--)
    {
        total = total + ((ISBN % 10) * i);
        ISBN /= 10;
    }

    if (total % 11 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}