#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// caesar.c
// encrypts using caesar cipher

#define MAX 80
#define NUM_IN_ALPHA 26
char encrypt(char *letter, int rot);
void usage(char *arg0);

int main(int argc, char *argv[])
{
	char *arg0 = argv[0];
	if ( argc < 2 )
	{
		usage(arg0);
		return 0;
	}
	unsigned int key = atoi(argv[1]);
	if ( key < 1 || key > 26 )
	{
		usage(arg0);
		return 0;
	}
    printf("Enter plaintext to be encoded\n");
	char *plaintext = GetString();
	char myvalue[MAX];
	char *ptr;
    for ( int i = 0; plaintext[i] != '\0'; i++ )
		ptr[i] = (char) encrypt(&plaintext[i], key);
	for ( int i = 0; plaintext[i] != '\0'; i++ )
		printf("%c", plaintext[i]);
	printf("\n");
	return 0;
}

void usage(char *arg0)
{
	printf("Usage: %s <AMT to rotate chars>\nAMT = 1-26 only.\n", arg0);
}

char encrypt(char *letter, int rot)
{
	for (int i = 0; letter[i] != '\0'; i++ )
	{
		if ( isspace(letter[i]) )
			letter[i] = letter[i];
		else if ( isupper(letter[i]) )
			letter[i] = (( (int) letter[i] - 'A') + rot) % NUM_IN_ALPHA + 'A';
		else if ( islower(letter[i]) )
			letter[i] = (( (int) letter[i] - 'a') + rot) % NUM_IN_ALPHA + 'a';
//			message[i]=((message[i]-'A') + shift) % 26 + 'A';
		else
			letter[i] = letter;
		return letter;
	}
}
