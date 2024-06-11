//madlib.c
// Derek Yee
// madlib

#include <stdio.h>
#include <cs50.h>

int main(void){
    int numberOfFriends = get_int ("How many friends are going on this journey with you? ");
    string name = get_string ("What is your name? ");
    int miles = get_int("Give me a number 5-20: ");
    int challenges = get_int("Give me a number 0-2: ");
    int hours = get_int("Give me a number 1-100: ");
    string adjective = get_string("Give me an adjective: ");
    string typeOfTerrian= get_string("Give me an adjective: ");
    string adjective2= get_string("Give me another adjective: ");
    string emotion= get_string("Give me an emotion: ");

    printf ("Once upon a time, %i brave souls embarked on a %s adventure. They covered %i miles in %i hours through %s terrain, facing %i challenges with %s determination. In the end,they reached their destination, feeling %s and accomplished. \n",numberOfFriends,adjective,miles,hours,typeOfTerrian,challenges,adjective2,emotion);


}