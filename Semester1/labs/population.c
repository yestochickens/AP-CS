// population.c
// Derek
// Calculates how many years to takes to get to a certain population size

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start Size: ");
        if (startSize < 9)
        {
            printf("not a valid starting population\n");
        }
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End Size: ");
        if (startSize > endSize)
        {
            printf("end size must be larger than start size\n");
        }
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (startSize < endSize)
    {
        int born = startSize / 3;
        int died = startSize / 4;
        startSize = startSize + born - died;
        years++;
    }

    // TODO: Print number of years
    if (startSize >= endSize)
    {
        printf("Years: %i\n", years);
    }
}
