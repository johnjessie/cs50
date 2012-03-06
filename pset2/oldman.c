#include <stdio.h>
#include <cs50.h>

#define VERSES 10

int
main(void)
{    
    string numbers[VERSES] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
    string played_on[VERSES] = { "on my thumb", "on my shoe", "on my knee", "on my door", "on my hive", "on my sticks", "up in heaven", "on my gate", "on my spine", "once again" };
    for (int i = 0; i < VERSES; i++)
    {
        printf("\nThis old man, he played %s\n", numbers[i]);
        printf("He played knick-knack %s\n", played_on[i]);
        printf("With a knick-knack paddywhack, give your dog a bone\nThis old man came rolling home.\n");
        // this waits for enter on first 9 before
        // continuing so you can see output
        if (i < (VERSES - 1))
            getchar();
    }
}