#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool keyIsCorrect(string key);

int main(int argc, string argv[])
{
    // check that 2 arugments is passed in
    if (argc != 2)
    {
        return 1;
    }
    // intializes key and runs keyIsCorrect function to check if the key is valid
    string key = argv[1];
    if (!keyIsCorrect(key))
    {
        return 1;
    }
    string sentence = get_string("plainText: ");

    for (int i = 0; i < strlen(sentence); i++)
    {
        // replaces lowercase letter with lowercase based on the key. Exp. a % 97 = 1. So sentence[i] = lowercase(key[1])
        if (islower(sentence[i]))
        {
            sentence[i] = tolower(key[sentence[i] % 97]);
        }
        // replaces lowercase letter with lowercase based on the key. Exp. A % 65 = 1. So sentence[i] = uppercase(key[1])
        if (isupper(sentence[i]))
        {
            sentence[i] = toupper(key[sentence[i] % 65]);
        }

    }
    printf("ciphertext: %s\n", sentence);
}

bool keyIsCorrect(string key)
{
    char letters[26];
    int letterCount = 0;
        for (int i = 0; i < strlen(key); i++)
        {
            if (isalpha(key[i]))
            {
                for (int j = 0; j < i; j++)
                {
                    // if key[i] is already in the letters array, keyIsCorrect returns false. Negates duplicate letters
                    if (key[i] == letters[j])
                    {
                        printf("Key must not contain duplicate letters");
                        return false;
                    }
                }
                // adds one to letter count
                letterCount++;
                // adds key[i] to the letter array so we can check it later
                letters[i] = key[i];
            }
            else
            {
                printf("The key can only contain letters");
                return false;
            }
        }
        // checks that length of key is 26
        if (letterCount == 26)
        {
            return true;
        }
        else
        {
            printf("Length must be 26 characters\n");
            return false;
        }
    }

