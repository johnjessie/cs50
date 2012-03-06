#include <stdio.h>
#include <cs50.h>
#include <string.h>

int
main(void)
{
    string cardnum = "123456789";
    int x[cardnum];
    for (int i = 0; i < (int) cardnum; i++)
        x[i] = (int) i;
    for (int j = 0; j < sizeof(x - 1); j++)
        printf("position %d is %d", j, x[j]);
}