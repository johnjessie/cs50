/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define BLANK 0


// global board
int board[DIM_MAX][DIM_MAX];
int sol[DIM_MAX][DIM_MAX];
int Dim;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
bool check(int row, int column);
void swap(int *a, int *b);

int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    Dim = atoi(argv[1]);
    if (Dim < DIM_MIN || Dim > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
		move(tile);
        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * void
 * clear()
 *
 * Clears screen using ANSI escape sequences.
 */

void
clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * void
 * greet()
 *
 * Greets player.
 */

void
greet()
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * void
 * init()
 *
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init()
{
    // TODO
    // Number to add to the array
    int maxnum = ( Dim * Dim ) - 1;
    // Loading the array
    // outer loops walk rows
    for (int i = 0; i <= Dim; i++)
    {
        // inner loop walks columns and has i counter 
        // and adds a j counter
        for (int j = 0; j <= Dim; j++)
        {
            board[i][j] = maxnum;
            maxnum--;
        }
    }
	/* Initialize solution board */
	int number = 1;
			
	for(int i = 0; i <= Dim - 1; i++)
	{
		for(int j = 0; j <= Dim - 1; j++)
		{
			if(number == maxnum)
			{
				sol[i][j] = maxnum;
				sol[i][j+1] = BLANK;
				break;
			}
			sol[i][j] = number;
			number++;
		}
	}
}


/* 
 * void
 * draw()
 *
 * Prints the board in its current state.
 */

void
draw()
{
    // TODO
    // gotta walk a 2d array so we need a nested for loop
    // like in init()
    int maxnum = (Dim * Dim) - 1;
    for ( int i = 0; i < Dim; i++ )
    {
        for ( int j = 0; j < Dim; j++ )
        {
            if ( board[i][j] >= maxnum && board[i][j] != 0 )
                printf("%2d", board[i][j]);
            else // if ( board[i][j] == 0 )
                printf("__", board[i][j]);
        }
    printf("\n\n");
    }
}


/* 
 * bool
 * move(int tile)
 *
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    // TODO
    // check array position for tile
    for ( int i = 0; i < Dim; i++ )
    {
        for (int j = 0; j < Dim; j++ )
        {
            if (!move(i,j))
                return false;
            else
            {
                swap(i,j);
                return true;
            }
        }
    }
    return false;
}

/*
 * bool
 * check(int row, int column)
 *                         
 * Checks whether the tile can be swapped or not. returns boolean
 */
 
/* Not anymore, check is now swaps if possible so its tweaked*/
//bool check(int row, int column)
bool check(int tile)
{
	// Input validation
	if (tile < 1 || tile > (Dim * Dim) - 1)
		return (false);

	int a1, a2, b1, b2;

	// Using linear search to locate empty tile
	for (int j = 0; j < Dim; j++)
	{
		for (int i = 0; i < Dim; i++)
		{
			if (board[j][i] == 0)
			{
				a1 = j;
				a2 = i;
				break;
			}
		}
	}

	for (int j = 0; j < Dim; j++)
	{
		for (int i = 0; i < Dim; i++)
		{
			if (board[j][i] == 0)
			{
				b1 = j;
				b2 = i;
				break;
			}
		}
	}
	
	// Checking if tiles are adjacent to each other
	if ( (a1 != b1 && a2 != b2) || abs(a1 - b1) > 1 || abs(a2 -b2) > 1)
		return (false);
	
	// Swapping tiles
	//int tmp = board[a1][a2];
	//board[a1][a2] = board[b1][b2];
	//board[b1][b2] = tmp;

	return (true);
}
/*
 * bool
 * won()
 *
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
void
swap(int *a, int *b)
{
	int tmp = board[a][b];
	board[a][b] = board[b1][b2];
	board[b1][b2] = tmp;
}

bool
won()
{
    // TODO
	int i,j;
	int sol[Dim][Dim];
		
	for(i = 0; i <= Dim - 1; i++)
	{
		for(j = 0; j <= Dim - 1; j++)
		{
			if(board[i],[j] != sol[i][j])
			{
				return (false);
			}
			return (true);
   		}
   	}
}
