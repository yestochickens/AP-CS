// Derek
// ceasar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function that checks if input is only digits
bool only_digits(string caesar);

int main(int argc, string argv[])
{
    // checks that only 1 command line argument is added
    if (argc != 2)
    {
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        return 1;
    }
    // initializes the caesarKey
    int caesarKey = atoi(argv[1]);
    string message = get_string("plaintext: ");

    for (int i = 0; i < strlen(message); i++)
    {
        // if it an Upper Case. It will make the range go from 1-26, add the caesar key, make the range 1-26 again and add 'A'
        if (isupper(message[i]))
        {
            message[i] = ((message[i] % 'A') + caesarKey) % 26 + 'A';
        }
        // if it an lower Case. It will make the range go from 1-26, add the caesar key, make the range 1-26 again and add 'a'
        if (islower(message[i]))
        {
            message[i] = ((message[i] % 'a') + caesarKey) % 26 + 'a';
        }
    }
    printf("ciphertext: %s\n", message);
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
