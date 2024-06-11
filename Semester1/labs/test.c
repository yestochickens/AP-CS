#include <crypt.h>
#include <stdio.h>

int main(void)
{
    //printf("%s", crypt("aaaba", "50"));

    for (int one = 'A'; one != '{'; one++)
    {
        if (one == 91)
        {
            one += 7;
        }
        else
        {
            printf("%i\n", one);
        }
    }

}

