#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// caesar.c
// encrypts using caesar cipher

#define MAX 80
#define TOTALPHA 26
char encrypt(char letter, int rot);
void usage(char *arg0);

int main(int argc, char *argv[])
{
	char *arg0 = argv[0];
	if ( argv[1] == 'NULL' )
	{
		unsigned int key = atoi(argv[1]);
		if ( argc < 2 || key < 1 || key > 26 )
		{
			usage(arg0);
		}
		printf("Enter plaintext to be encoded\n");
		char *plaintext = GetString();
		char myvalue[MAX];
		char *ptr = myvalue;
		int loop1ctr = 0;
		for ( int i = 0; plaintext[i] != '\0'; i++ )
		{
			loop1ctr++;
			ptr[i] = (char) encrypt(plaintext[i], key);
		}
		ptr[loop1ctr] = '\0';
		for ( int i = 0; myvalue[i] != '\0'; i++ )
			printf("%c", myvalue[i]);
		printf("\n");
		return 0;
	}
	else
		usage(arg0);
}

void usage(char *arg0)
{
	printf("Usage: %s <AMT to rotate chars>\nAMT = 1-26 only.\n", arg0);
}

char encrypt(char letter, int rot)
{
		if ( isspace(letter) )
			letter = letter;
		else if ( isupper(letter) )
			letter = (( (int) letter - 'A') + rot) % TOTALPHA + 'A';
		else if ( islower(letter) )
			letter = (( (int) letter - 'a') + rot) % TOTALPHA + 'a';
//			message[i]=((message[i]-'A') + shift) % 26 + 'A';
		else
			letter = letter;
		return letter;
}
