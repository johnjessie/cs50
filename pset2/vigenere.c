/***************************************************************************
 * vigenere.c
 *
 * Computer Science 50
 * Problem Set 2
 *
 * Implements vigenere cipher
 *
 * Usage: vigenere <codeword>
 *
 * whereby the codeword sets the rotational value 
 * that the plaintext will be encoded by determining
 * distance from 'a' and using that value to rotate
 * each char in plaintext, looping codeword if codeword
 * is shorter than plaintext
 *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

#define MAX 80
#define TOTALPHA 26

char encrypt(char pletter, int rot);
void usage(char *arg0);
char findkey(char pletter, char cletter);

int main(int argc, char *argv[])
{
	char *arg0 = argv[0];
	if ( argv[1] == 'NULL' || !isalpha(argv[1]) )
	{
		char *codeword = argv[1];
		printf("Enter plaintext to be encoded\n");
		char *plaintext = GetString();
		char output[(sizeof(plaintext))];
		int counter_c = 0;
		printf("The codeword is: %s \n", codeword);
		for ( int i = 0; plaintext[i] != '\0'; i++ )
		{
			while ( codeword[counter_c] != '\0' && plaintext[i] != '\0' )
			{
				output[i] = (char) findkey(plaintext[i], codeword[counter_c]);
				counter_c++;
			}
			if ( plaintext[i] != '\0' )
			{
				counter_c -= strlen(codeword);
				output[i] = findkey(plaintext[i], codeword[counter_c]);
			}
		}
		printf("%s \n", output);
		printf("\n");
		return 0;
	}
	else
		usage(arg0);
}

char findkey(char pletter, char cletter)
// takes char pletter = plaintext letter, char cletter = codeword letter
// calls encrypt and passes pletter and keyval ( keyval = alpha distance
// from 'a')
{
	int keyval = 0;
	char ctext = tolower(cletter);
	keyval = ( (int) ctext - 'a') % TOTALPHA;
	ctext = encrypt(pletter, keyval);
	return ctext;
}

char encrypt(char pletter, int rot)
// takes char pletter and int rot, rotates pletter by rot and returns
// pletter
{
		if ( isspace(pletter) )
			pletter = pletter;
		if ( isupper(pletter) )
			pletter = (( (int) pletter - 'A') + rot) % TOTALPHA + 'A';
		if ( islower(pletter) )
			pletter = (( (int) pletter - 'a') + rot) % TOTALPHA + 'a';
		else
			pletter = pletter;
		return pletter;
}

void usage(char *arg0)
// Usage message
{
	printf("Usage: %s <codeword>\ncodeword = letters only.\n", arg0);
}
