// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool number = false;
    bool lower = false;
    bool upper = false;
    bool punc = false;
    for (int i = 0; i < strlen(password); i++)
    {
        // checks for each condition for each letter
        if (isdigit(password[i]))
        {
            number = true;
        }
        else if (islower(password[i]))
        {
            lower = true;
        }
        else if (isupper(password[i]))
        {
            upper = true;
        }
        else if (ispunct(password[i]))
        {
            punc = true;
        }
    }
    // if all conditions are meant it will return true
    if (lower && upper && number && punc)
    {
        return true;
    }
    else
    {
        return false;
    }
}
