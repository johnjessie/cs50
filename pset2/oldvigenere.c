#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// vigenere.c
// encrypts using vigenere cipher

#define MAX 80
#define TOTALPHA 26
char encrypt(char letter, int rot);
void usage(char *arg0);
int findkey(char capletter);

int main(int argc, char *argv[])
{
	char *arg0 = argv[0];
	if ( argv[1] == 'NULL' || !isalpha(argv[1]) )
	{
		char *codeword = argv[1];
		printf("Enter plaintext to be encoded\n");
		char *plaintext = GetString();
		char myvalue[MAX];
		char *ptr = myvalue;
		for ( int i = 0; plaintext[i] != '\0'; i++ )
		{
			int loop1ctr = 0;
			for ( int j = 0; codeword[j] != '\0'; i++ )
			{
				loop1ctr++;
				ptr[i] = (char) encrypt(plaintext[i], findkey(toupper(codeword[j])));
			}
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

void walkover(char *plaintext, char *codeword)
{
	char *ptr_p = plaintext;
	char *ptr_c = codeword;
	int pos_p = 0;
	while ( ptr_p != '\0' )
	{
		int pos_c = 0;
		for ( int i = 0; ptr_c != '\0'; i++ )
		{
			ptr_p = (char) encrypt(ptr_p[pos_p], findkey(toupper(ptr_c[i])))
	}

int findkey(char capletter)
{
	int keyval = 0;
	keyval = ((int) capletter - 'A') % TOTALPHA;
	return keyval;
}

void usage(char *arg0)
{
	printf("Usage: %s <codeword>\ncodeword = letters only.\n", arg0);
}

char encrypt(char letter, int rot)
{
		if ( isspace(letter) )
			letter = letter;
		if ( isupper(letter) )
			letter = (( (int) letter - 'A') + rot) % TOTALPHA + 'A';
		if ( islower(letter) )
			letter = (( (int) letter - 'a') + rot) % TOTALPHA + 'a';
//			message[i]=((message[i]-'A') + shift) % 26 + 'A';
		else
			letter = letter;
		return letter;
}
