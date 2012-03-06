#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// caesar.c
// encrypts using caesar cipher

#define MAX 512
#define NUM_IN_ALPHA 26
char encrypt(char *letter, int rot);

int main(int argc, string argv[])
{
	int key = atoi(argv[1]);
	printf("Enter plaintext to be encoded\n");
	char *plaintext = GetString();
	for ( int i = 0; plaintext[i] != '\0'; i++ )
	{
		letter = plaintext[i];
		ciphertext[i] = encrypt(letter, key);
	}
	printf("%s", plaintext);
}

char encrypt(char *letter, int rot)
{
	int mynumber = (int) letter;
    if ( isspace(letter) )
		;
	else if ( isupper(letter) )
		letter = ( (int) letter - 'A' + rot) % NUM_IN_ALPHA + 'A';
	else if ( islower(letter) )
		letter = ( (int) letter - 'a' + rot) % NUM_IN_ALPHA + 'a';
	else
		letter = letter;
	return letter;
}
