#####################
# <skittles.c>              
#  06-19-11 John Jessie
#  <Harvard #CS50 Problem 1 pset 1> 
#  Simple guessing game
#
#
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    // seed PRNG
    srand(time(NULL));
    
    // pick pseudorandom number in [0, 1023]
    int skittles = rand() % 1024;
    
    int guess = 0;
    do
    {
        printf("There are between 1-1023 skittles\nEnter your guess: ");
        int guess = GetInt();
        if (guess > skittles)
        {
            printf("Too High, try again.");
        }
        else if (guess < skittles)
        {
            printf("Too low, try again.");
        }
        else
        {
            printf("Your guess of %d was correct! There are %d skittles", guess, skittles);
            break;
        }
    } while (guess != skittles);
}