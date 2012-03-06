#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
#####################
# <vigenere.c>              
#  06-28-11 John Jessie
#  <encrypts using vigenere cipher> 
#   Usage: ./vigenere <keyword>
#   keyword specifies string array
#   to be used as rot values
#   passed to encrypt()
*/ 

#define MAX 80
#define NUM_IN_ALPHA 26

// prototypes
char encrypt(char *letter, int rot);
int findkey(char keyval);
char walkover(char *ptext, char *ctext, char *key);

int main(int argc, string argv[])
{
   	char *key = argv[1];
	printf("Enter plaintext to be encoded\n");
	char *ptext = GetString();
	char ciphertext[MAX];
//	char *ctext = &ciphertext;
	char ctext[MAX] = walkover(ptext, ciphertext, key);
//	char letter;
	// Outer loop
	printf("\nEncoded text:\n");
//	char output = walkover(ptext, key);
	for ( int i = 0; ctext[i] != '\0'; i++ )
		printf("%c", ctext[i]);
}

char walkover(char *ptext, char *ctext, char *key)
{
	char myvalue[MAX];
	char myptext[MAX];
	if ( isalpha(myptext) )
	{
		int pos = 0;
		while ( ctext[pos] != '\0' )
		{
			for ( int i = 0; myptext[i] != '\0'; i++ )
			{
				char myvalue = encrypt( myptext[i], findkey(key[pos]));
				walkover(myptext[i], ctext[pos], key[pos]);
				pos++;
		}
        pos = 0;
		}
	}
	return myvalue;
}


char encrypt(char letter, int rot)
{
	if ( isalpha(letter) )
	{
		int mynumber = (int) letter;
		char *myencvalue;
		if ( isspace((char)mynumber) )
			myencvalue = (int)' ';
		else if ( isupper((char)mynumber) )
			myencvalue = (mynumber - 'A' + rot) % NUM_IN_ALPHA + 'A';
		else if ( islower((char)mynumber) )
			myencvalue = (mynumber - 'a' + rot) % NUM_IN_ALPHA + 'a';
		else
			myencvalue = (char)letter;
		return myencvalue;
	}
}

int findkey(char keyval)
{
    int myrot = (int) keyval;
    int myvalue;
    if ( isspace((char)myrot) )
        myvalue = (int)' ';
    else if ( isupper((char)myrot) )
        myvalue = (myrot - 'A'); // + 'A';
    else if ( islower((char)myrot) )
        myvalue = (myrot - 'a'); // + 'a';
    else
        myvalue = 0;
    return myvalue;   
}
