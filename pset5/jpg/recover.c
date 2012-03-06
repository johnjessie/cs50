/*
 * recover.c
 *
 *
 * recovers deleted jpg photos from a forensic image.
 *
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef uint8_t		BYTE;

int
main (int argc, char *argv[])
{
	FILE *myfile = fopen ("card.raw", "r");
	// open input file
	if (myfile == NULL)
	// check for null pointer == fopen failed to open
	{
		printf("The image file couldn't be opened.\n");
		return 1;
	}

	// initialize array named buffer with space for 512 bytes
	BYTE *buffer = malloc(BLOCK_SIZE * sizeof(BYTE));

	// prior to reading file, writingfile is false
	bool writingfile = false;
	
	// jpgs_found is used to name files, 
	// which is why it starts at 1 and not 0
	int jpgs_found = 1;

	// init char *array of size 2
	char *outfilename = malloc(2 * sizeof(char));

	// init FILE pointer *outfile to NULL
	FILE *outfile = NULL;


	// read file loop till EOF is reached
	while (feof(myfile) == 0)
	{
		// read 512 byte block into buffer from myfile
		fread(buffer, BLOCK_SIZE, 1, myfile);

		// check first 4 buffer slots for jpeg signature in int values
		if ( (buffer[3] == 224 || buffer[3] == 225) && ( buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 ) )
		{
			// if writingfile is still true close it
			if (writingfile == true)
				fclose(outfile);

			// indicate we've found an image
			writingfile = true;
			// concatenate jpgs_found with .jpg using 2 place 
			// holders and store in char * outfilename
			sprintf(outfilename, "%.2d.jpg", jpgs_found);
			// increment jpgs_found for naming
			jpgs_found++;
			// open the outfilename file in "a" - append mode
			outfile = fopen(outfilename, "a");

			// check that fopen didn't return a null pointer
			if (outfile == NULL)
			{
				printf("could not create jpeg file.\n");
				return 1;
			}
			// start writing buffer to outfile
			fwrite(buffer, BLOCK_SIZE, 1, outfile);
		}
		// continue writing to outfile if writingfile
		// is still true.
		else if (writingfile == true)
		{
			// walk the buffer checking for end of image signature
			for (int i = 0; i < BLOCK_SIZE; i ++)
				{
					// check for end of image signature
					if (buffer[i] == 255 && buffer[i + 1] == 217)
					{
						// write the signature to outfile
						fwrite(&buffer[i], 1, 1, outfile);
						fwrite(&buffer[i + 1], 1, 1, outfile);
						// close outfile
						fclose(outfile);
						// toggle writingfile
						writingfile = false;
					}
					// no end of image signature in &buffer[i]
					// write buffer[i] to file and move on
					fwrite(&buffer[i], 1, 1, outfile);
				}
		}
	}

	// output number of jpgs found by decrementing jpgs_found
	// since it started at 1 for naming purposes
	printf("I believe I found %d jpegs.\n", --jpgs_found);

	// close card.raw
	fclose(myfile);

	// close last outfile
	fclose(outfile);
}
