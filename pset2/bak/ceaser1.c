#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

// ceaser.c 
// encrypts using ceaser cipher

#define MAX 512
#define NUM_IN_ALPHA 26
char encrypt(char letter, int rot);

int main(int argc, string argv[])
{
   	int key = atoi(argv[1]); 
   	printf("Enter plaintext to be encoded\n");
	string plaintext = GetString();
	char ciphertext[MAX];
	char letter;
	for ( int i = 0; plaintext[i] != '\0'; i++)
	{
		letter = plaintext[i];
	   	ciphertext[i] = encrypt(letter, key);
	}
 	for ( int j = 0; ciphertext[j] != '\0'; j++)
	{    
	   	printf("%c", ciphertext[j]);
	}
}

char encrypt(char letter, int rot)
{
    int mynumber = (int) letter;
	char myvalue;
	if ( isspace(letter) )
		myvalue = (int)' ';
	else if ( isupper(letter) )
		myvalue = (char)(mynumber - 'A' + rot) % NUM_IN_ALPHA + 'A';
	else if ( islower(letter) )
		myvalue = (char)(mynumber - 'a' + rot) % NUM_IN_ALPHA + 'a';
	else
		myvalue = (char)letter;
	return myvalue;
}
