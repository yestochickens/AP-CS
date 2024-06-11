#include <stdio.h>
#include <cs50.h>

// Nested for Loops (rows / col)

int main (void)
{
    for(int i = 0; i < 3; i++)
    {
        printf("#");
        for (int j = 0; j < 4; j++)
        {
            printf(".");
        }
    }

    printf("\n");
}