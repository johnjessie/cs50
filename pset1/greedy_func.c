/*#####################
# <greedy_func.c>              
#  06-21-11 John Jessie
#  <Harvard Computer Science 50>
#  Pset 1 Problem 2 - remixed
#  **Now using a function**
#  **And pointers**
# 
#  greedy algorithm to determine fewest
#  coins to pay out amount from input
#  use only quarters, dimes, nickels, and pennies.
#  < for funsies I put some dollar stuff in :-} >
#
#####################*/
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int makechange(int *mypennies, int mycoin_amt, int *counter1, int *counter2);

int main(void) {
    // get input
    printf("O hai!  How much change is owed?\n$");
    float change = GetFloat();
    // check input
    if (change <= 0) {
        printf("Please enter a positive number");
        float change = GetFloat();
    }
    int my_pennies = (int) round(change * 100);
    printf("\nOk so I owe you $%.2f\n", change);
    // initialize some variables
    int coins, quarters, dimes, nickels, pennys;
    coins = quarters = dimes = nickels = pennys = 0;
    // nested do inside of do-while loop to calculate
    // coin usage.
    do
    {
   //  quarters 
        while (my_pennies >= 25) {
            makechange(&my_pennies, 25, &coins, &quarters);
        }
    // dimes
        while (my_pennies >= 10) {
            makechange(&my_pennies, 10, &coins, &dimes);
        }
    // nickels
        while (my_pennies >= 5) {
            makechange(&my_pennies, 5, &coins, &nickels);
        }
    // Pennies
        while (my_pennies >= 1) {
            makechange(&my_pennies, 1, &coins, &pennys);
        }
    } 
    while (my_pennies > 0);
    
    // Output results
    printf("\nYour change will be in the form of:\n%d quarters\t%d dimes\n%d nickels\t%d pennies\n", quarters, dimes, nickels, pennys);
    printf("Here's how many coins I gave you: %d\n", coins);
    // calculate dollars and remainder quarters
    int dollars = quarters / 4;
    int rem_d = quarters % 4;
    // output dollar based results
    printf("\nIf i could have used dollars you would have received:\n%d dollars\t%d quarters\t%d dimes\n%d nickels\t%d pennies.\n", dollars, rem_d, dimes, nickels, pennys);
    printf("I would have given you %d coins and %d dollar bills.", (coins - (dollars * 4)), dollars);
}

int makechange(int *mypennies, int mycoin_amt, int *counter1, int *counter2) {
    *mypennies = *mypennies - mycoin_amt;
    *counter1 = *counter1 + 1;
    *counter2 = *counter2 + 1;
}
