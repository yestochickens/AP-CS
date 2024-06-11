// takes a string and prints every letter

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string word = get_string("Type a word: ");
    long length = strlen(word);


    for (int i = length-1; i >= 0; i--)
    {
        printf("%c \n", word[i]);
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c \n", word[i]);
    }

}