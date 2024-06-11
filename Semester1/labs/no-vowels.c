// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string sentence);

int main(int argc, string argv[])
{
    // checks if there are two command line arguments
    if (argc != 2)
    {
        return 1;
    }
    string input = argv[1];
    printf("%s\n", replace(input));
}

string replace(string sentence)
{
    for (int i = 0; i < strlen(sentence); i++)
    {
        // for each letter in the sentence, if it is a vowel, it is replaces
        switch (sentence[i])
        {
            case 'a':
                sentence[i] = '6';
                break;
            case 'e':
                sentence[i] = '3';
                break;
            case 'o':
                sentence[i] = '0';
                break;
            case 'i':
                sentence[i] = '1';
                break;
        }
    }
    return sentence;
}
