/********************************************************
* pset2 2_greedy.c
*
* asks for user input and 
* uses greedy algorithm to minimize coins returned as change
*********************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    // variables
    float n;
    float change;//
    // 1. Welcome
    printf("\n");
    printf("\n");
    printf("O Hai! Let's play a game called 'Time for a Change'\n");
    printf("How much change do you need? (put in $0.00 form pls)\n");
    printf ("$ ");
    //
    // 2. User Geusses
    n = GetFloat();
    //
    // If input <= 0
    while (n <= 0)
    {    if (n <= 0)
        {
            printf("Sorry, negative or zero dollars means no change! Please try again:\n");
            n = GetFloat();
        }
    }
    if (n > 0)
    {
        change = n * 100;
    }
    printf("You mean %.f cents?\n", change);
        int result_q = change / 25;
        int rem_q = change - (result_q * 25);
        int result_d = rem_q / 10;
        int rem_d = rem_q - (result_d * 10);
        int result_n = rem_d / 5;
        int rem_n = rem_d - (result_n * 5);
        int result_p = rem_n;
        int coins = result_q + result_d + result_n + result_p;
    printf("I'm going to give you %d coins:\n", coins);
    printf("  %d quarters\n", result_q);
    printf("  %d dimes\n", result_d);
    printf("  %d nickles\n", result_n);
    printf("That should leave you with %d cents left over\n", result_p);
    printf("\n");
}