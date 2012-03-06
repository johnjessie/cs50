#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ceaser.c 
// encrypts using ceaser cipher
//char* Itoa(int value, char* str, int radix);
#define MINREQUIRED 2
#define MAX 80

int
main(int argc, string argv[])
{
	if (argc < MINREQUIRED)
	{
		printf("Usage %s <# to shift by>", argv[0]);
		return 1;
	}
	int key = atoi(argv[1]);
	printf("Input a string: ");
	string plaintext = GetString();
	char *text_p = plaintext;
	for (int i = 0; plaintext[i] != '\0'; i++)
	{
		if (isupper(*text_p))
		{
			//*text_p += (char) key;
			if (*text_p < 'Z')
				//*text_p -= 26;
				*text_p = ((( (char) text_p - 'A') + key ) % 26 + 'A');
		}
		else if (islower(*text_p))
		{
			//*text_p += (char) key;
			if (*text_p < 'z')
				//*text_p -= 26;
				*text_p = ((( (char) text_p - 'a' ) + key ) % 26 + 'a');
				//csr_let = (((pln_txt[i] - 'a') + k) % 26 + 'a');
		}
		else if (isspace(*text_p))
		{
			;
		}
		else if (!isalnum(*text_p))
		{
			;
		}
		text_p++;
	}
//	for (int j = 0; plaintext[j] != '\0'; j++)
//		printf("%c", plaintext[j]);
	printf("%s", plaintext);
	return 0;
}
