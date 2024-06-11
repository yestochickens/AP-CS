#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int wordCount(string sentence);
int letterCount(string sentence);
int sentenceCount(string sentence);

int main(void)
{
    string text = get_string("Your Sentence: ");
    int letters = letterCount(text);
    int words = wordCount(text);
    int sentences = sentenceCount(text);
    float index = 0.0588 * ((float) (letters) *100 / words) - 0.296 * ((float) sentences * 100 / words) - 15.8;
    if ((int) round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int) round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int wordCount(string sentence)
{
    int wordCount = 1;
    for (int i = 0; i < strlen(sentence); i++)
    {
        // checks for spaces and adds to word count
        if (sentence[i] == ' ')
        {
            wordCount += 1;
        }
    }
    return wordCount;
}

int letterCount(string sentence)
{
    int letterCount = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        // checks if charater is uppercase or losecase letter then adds to letter count
        if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122))
        {
            letterCount += 1;
        }
    }
    return letterCount;
}

int sentenceCount(string sentence)
{
    int sentenceCount = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        // checks for punctuations and adding to sentence count
        if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == '?')
        {
            sentenceCount += 1;
        }
    }
    return sentenceCount;
}
