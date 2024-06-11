// Derek
// crack.c
// finds a persons password

#include <crypt.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define A 'A'
#define last 'z+1'

int main(int argc, string argv[])
{
    // check that a user a inputed a hash
    if (argc != 2)
    {
        printf("Input a hash\n");
        return 1;
    }
    string encrypted = argv[1];
    // makes an array for the password we are testing
    char password[6];
    // last character is null so it hashes like a string
    password[5] = '\0';

    for (int one = A; one != last; one++)
    {
        for (int two = A; two != last; two++)
        {
            for (int three = A; three != last; three++)
            {
                for (int four = A; four != last; four++)
                {
                    for (int five = A; five != last; five++)
                    {
                        // when it gets to the end of capital letters it goes straight to lowercase letters
                        if (five == 91)
                        {
                            five += 5;
                        }
                        else
                        {
                            // sets the password array to new password we are testing
                            password[0] = one;
                            password[1] = two;
                            password[2] = three;
                            password[3] = four;
                            password[4] = five;
                            // checks if hash of password matches inputed hash
                            if (strcmp(crypt(password, "50"), encrypted) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                            printf("%c%c%c%c%c\n", one, two, three, four, five);
                        }
                    }
                    if (four == 90)
                    {
                        four += 6;
                    }
                    else
                    {
                        password[0] = one;
                        password[1] = two;
                        password[2] = three;
                        password[3] = four;
                        password[4] = '\0';
                        if (strcmp(crypt(password, "50"), encrypted) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                        printf("%c%c%c%c\n", one, two, three, four);
                    }
                }
                if (three == 90)
                {
                    three += 6;
                }
                else
                {
                    password[0] = one;
                    password[1] = two;
                    password[2] = three;
                    password[3] = '\0';
                    if (strcmp(crypt(password, "50"), encrypted) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                    printf("%c%c%c\n", one, two, three);
                }
            }
            if (two == 90)
            {
                two += 6;
            }
            else
            {
                password[0] = one;
                password[1] = two;
                password[2] = '\0';
                if (strcmp(crypt(password, "50"), encrypted) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
                printf("%c%c\n", one, two);
            }
        }
        if (one == 90)
        {
            one += 6;
        }
        else
        {
            password[0] = one;
            password[1] = '\0';

            if (strcmp(crypt(password, "50"), encrypted) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            printf("%c\n", one);
        }
    }
}
