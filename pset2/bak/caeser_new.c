#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ceaser.c 
// encrypts using ceaser cipher
// this is some of the magic done by case
// asc_ch = (( (char)ch - 'a' + key) % 26) + 'a'; // lower
// asc_ch = (( (char)ch - 'A' + key) % 26) + 'A'; // upper

#define MAX 512

int
main(int argc, string argv[])
{
    //int key = atoi(argv[1]);
    char plaintext = GetChar();
    int stringlen = strlen(plaintext);
    for ( int i = 0; i < stringlen; i++)
        printf("%s\n", plaintext[i]);
}