#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
main(void)
{
	int myintarray[10] = {97,98,99,100,101,102,103,104,105,106};
	char mychararray[10];
	for (int i = 0; i < 10; i++)
		mychararray[i] = (char)myintarray[i];
	for (int i = 0; i < 10; i++)
		printf("%c", mychararray[i]);
}
