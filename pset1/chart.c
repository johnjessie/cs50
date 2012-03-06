#include <stdio.h>
#include <cs50.h>

#define NUMBERS 4 // will be size of array

int
main(void)
{
    int spotting[NUMBERS], i, j, sum;
    float perc[NUMBERS];
    char sex1, sex2;
    
    // ask for input, store in spotting[]
    printf("\nWho is spotting who?\n\n");
    for (i = 0; i < NUMBERS; i++)
    {
        // display correct M/F depending on iteration
        sex1 = ((i == 0) || (i == 3)) ? 'M' : 'F';
        sex2 = ((i == 1) || (i == 3)) ? 'M' : 'F';
        
        // get numbers
        printf("%c spotting %c: ", sex1, sex2);
        spotting[i] = GetInt();
        
        // don't allow negative numbers
        while (spotting[i] < 0)
        {
            printf("No negative number please: ");
            spotting[i] = GetInt();
        }
    }
    
    /* calculate sum of 4 numbers
     for loop cycles through each array slot
     and adds each number to the total */
    sum = 0;
    for (i = 0; i < NUMBERS; i++)
        sum += spotting[i];
    printf("\nResults:\n\n");
    
    
    /* inner loop: for each % print num of '#' to
       make bar length */
    for (i = 0; i < NUMBERS; i++)
    {
        /* display correct M/F depending on iteration */
        sex1 = ((i == 0) || (i == 3)) ? 'M' : 'F';
        sex2 = ((i == 1) || (i == 3)) ? 'M' : 'F';
        
        /* work out % of total sum for each
       number in spotting[i] and store in perc[i] */
        perc[i] = (spotting[i] / (float)sum) * 100;
        printf("%c spotting %c\n", sex1, sex2);
        
        // print bar
        for (j = 0; j < 0.8 * (int)perc[i]; j++)
            printf("#");
        printf("\n");
    }
    printf("\n");
}
    