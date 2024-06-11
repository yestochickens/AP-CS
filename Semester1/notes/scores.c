#include <stdio.h>
#include <cs50.h>

// #define ARRAYLENGTH 10

// global variable
const int numScores = 10;

float average(int array[]);

int main(void)
{
    // must declare list size
    int scores[numScores];

    for (int i = 0; i < numScores; i++)
    {
        scores[i] = get_int("Score: ");
    }
    // scores = [72, 73, 33]


    printf("%0.2f\n ", average(scores));
}

float average(int array[])
{
    int total = 0;
    for (int i = 0; i < numScores; i++)
    {
        total += array[i];
    }
    return total / (float)numScores;
}