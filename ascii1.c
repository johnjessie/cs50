/*#####################
# <ascii1.c>              
#  06-22-11 John Jessie
#  < >
#  
# 
#####################*/
#include <stdio.h>

int
main( int argc, char *argv[])
{
    // display mapping for uppercase letters
    for (int i = 65; i < (65 + 26); i++)
    // original code below
    //  printf("%c: %d", (char) i, i);
    // below is added by me for better printing
        if ( i % 2 ) {
            printf("%c: %d", (char) i, i);
        }
        else {
            printf("\t%c: %d\n", (char) i, i);
        }
        
    // separate upercase from lowercase
    printf("\n");
    
    // display mapping for lowercase letters
    for (int i = 97; i < (97 + 26); i++)
    // More of my handiwork below, for formatting
        if ( i % 2 ) {
            printf("%c: %d", (char) i, i);
        }
        else {
            printf("\t%c: %d\n", (char) i, i);
        }
}