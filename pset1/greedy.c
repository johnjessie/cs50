/*#####################
# <greedy.c>              
#  06-19-11 John Jessie
#  <Harvard Computer Science 50>
#  Pset 1 Problem 2
# 
#  greedy algorithm to determine fewest
#  coins to pay out amount from input
#  use only quarters, dimes, nickels, and pennies.
#  < for funsies I put some dollar stuff in :-} >
#
#####################*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>


int
main(void)
{
    // get input
    printf("O hai!  How much change is owed?\n");
    float change = GetFloat();
    // check input
    if (change <= 0)
    {
        printf("Please enter a positive number");
        float change = GetFloat();
    }
    int my_pennies = (int) round(change * 100);
    // initialize some variables
    int coins, quarters, dimes, nickels, pennys;
    coins = quarters = dimes = nickels = pennys = 0;
    // nested do inside of do-while loop to calculate
    // coin usage.
    do
    {
        while (my_pennies >= 25)
        {
            my_pennies = my_pennies - 25;
            coins++;
            quarters++;
        }
    // dimes
        while (my_pennies >= 10)
        {
            my_pennies = my_pennies - 10;
            coins++;
            dimes++;
        }
    // nickels
        while (my_pennies >= 5)
        {
            my_pennies = my_pennies - 5;
            coins++;
            nickels++;
        }
    // Pennies
        while (my_pennies >= 1)
        {
            my_pennies = my_pennies - 1;
            coins++;
            pennys++;
        }
    } 
    while (my_pennies > 0);
    // Output results
    printf("\nYour change will be in the form of:\n%d quarters\n%d dimes\n%d nickels\n%d pennies\n", quarters, dimes, nickels, pennys);
    printf("Here's how many coins I gave you: %d\n", coins);
    int dollars = quarters / 4;
    int rem_d = quarters % 4;
    printf("\nIf i could have used dollars you would have received:\n%d dollars\n%d quarters\n%d dimes\n%d nickels\n%d pennies.\n", dollars, rem_d, dimes, nickels, pennys);
}
