/******************************************************************************
 * stringiter.c
 * Matthew Chartier
 * CS50/CSCI E-52
 *
 * Iterating over a string. Prints out each char on separate lines.
 *****************************************************************************/

#include <stdio.h>
#include <cs50.h>

int main (int argc, char* argv[])

{
    string text = "strings are arrays";
    for(int i = 0; text[i] != '\0'; i++)
    {
        printf("text[%d] == %c\n", i, text[i]);
    }  
}