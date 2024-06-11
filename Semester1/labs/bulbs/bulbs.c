#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string word = get_string("Type a word: ");

    for (int i = 0; i < strlen(word); i++)
    {
        int bit[8];
        int decimal = word[i];

        for (int digitsPlace = 7; digitsPlace >= 0; digitsPlace--)
        {
            // checks if 2^digitsPlace can fit into the decimal number.
            if (pow(2, digitsPlace) <= decimal)
            {
                // subtract that amount from decimal and makes that digits place = 1
                bit[7 - digitsPlace] = 1;
                decimal -= pow(2, digitsPlace);
            }
            else
            {
                // makes that digits place = 0
                bit[7 - digitsPlace] = 0;
            }
        }
        // loops through the array and prints out the bulbs
        for (int j = 0; j < 8; j++)
        {
            print_bulb(bit[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
