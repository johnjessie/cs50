/*#####################
# <credit.c>              
#  06-21-11 John Jessie
#  <Harvard Computer Science 50>
#  <hacker edition>
#  This program will validate 
#  credit card numbers using 
#  Luhn's algorithm.
#
#  1. multiply EVERY OTHER digit by 2, 
#  starting with the number's SECOND
#  TO LAST digit. Then add those
#  products digits together.
#
#  2. Add the sum to the sum of the
#  digits that weren’t multiplied by 2.
#
#  3. if the total's last digit is 0
#  (or, put more formally, if the total 
#  modulo 10 is congruent to 0), the 
#  number is valid!
#####################*/

#include <stdio.h>
#include <cs50.h>
#include <limits.h>
#include <stdlib.h>

int
main()
{
    string mycard = "378282246310005";
    long testcard[14];
    for (int i = 0; i < 14; i++)
        testcard[i] = strtoul(mycard);
        printf("position %d is %llu", i, testcard[i]);
}

 