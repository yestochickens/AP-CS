//GradeCaluculator
//Derek
//Determines your grade

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int grade = get_int("What was your grade percentage? ");

    if (grade >= 90)
    {
        printf("you got an A\n");
    }
    else if (grade >= 80)
    {
        printf("You got a B\n");
    }
    else if (grade >= 70)
    {
        printf("You got a C\n");
    }
    else if (grade >= 60)
    {
        printf("You got a D\n");
    }
    else
    {
        printf("You failed :(\n");
    }
}