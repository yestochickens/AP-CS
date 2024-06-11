// Modifies the volume of an audio file

#include <cs50.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// checks that txt file only has characters
bool only_digits(string caesar);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./encrypt input.txt output.txt shift\n");
        return 1;
    }
    if (!only_digits(argv[3]))
    {
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t character;
    int shift = atoi(argv[3]);

    // reads one character at a time
    while (fread(&character, sizeof(char), 1, input))
    {
        if (isupper(character))
        {
            character = ((character % 'A') + shift) % 26 + 'A';
        }
        // if it an lower Case. It will make the range go from 1-26, add the caesar key, make the range 1-26 again and add 'a'
        if (islower(character))
        {
            character = ((character % 'a') + shift) % 26 + 'a';
        }
        // writes out the new character after the shift
        fwrite(&character, sizeof(char), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}

bool only_digits(string caesar)
{
    // checks that all the chacters in the command line argument is a digit
    for (int i = 0; i < strlen(caesar); i++)
    {
        if (!isdigit(caesar[i]))
        {
            return false;
        }
    }
    return true;
}
