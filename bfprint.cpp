/*
 * bfprint.cpp
 * pass in a string and it turns your text into bf code for printing
 *
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// cell 1 for capitals starting at A 
	// cell 2 for lowercase starting at a 
	// cell 3 for most special characters starting at space going to @
	// cell 4 for a small chunk of special characters from [ to `
	// cell 5 for a small chunk of special characters from { to ~
	// cell 6 for extended ascii codes
	// starts on cell 1
	char *text;
	const char *bfopen = "++++++++++[>++++++>+++++++++>+++>+++++++++>++++++++++++<<<<<-]>+++++>+++++++>++>+>+++<<<<";
	
	// sets all the last to get the position for next time set to the first in their list
	char lastUpper = 'A';
	char lastLower = 'a';
	char lastSC1 = ' ';
	char lastSC2 = '[';
	char lastSC3 = '{';
	
	// set the current cell to 0 which is cell 1
	int currentCell = 0;
	// our last cell defaulting to 0
	int lastCell = 0;
	// our last pointer which will point to the last characters above
	char *lastWut;
	// for our loops
	int i, j;
	
	text = (char*)malloc(30001);
	
	// if we aren't passing it in with the command we grab from stdin go pipe!
	if (argc < 2)
		fgets(text, 30000, stdin);
	// if we are passing in our bf code then copy the memory into k
	else if (argc == 2)
		memcpy(text, argv[1], strlen(argv[1]));

	// we start off by printing the "setup" bf code
	printf("%s", bfopen);
	
	// here is where we loop through each of the characters
	for (i = 0; i < strlen(text); i++)
	{
		int distance = 0;
		char push;
		
		// crude and rude but it does the job we just get ranges for our cells
		if      ((char)text[i] >= (char)'A' && (char)text[i] <= (char)'Z') { lastWut = &lastUpper; currentCell = 0; }
		else if ((char)text[i] >= (char)'a' && (char)text[i] <= (char)'z') { lastWut = &lastLower; currentCell = 1; }
		else if ((char)text[i] >= (char)' ' && (char)text[i] <= (char)'@') { lastWut = &lastSC1; 	 currentCell = 2; }
		else if ((char)text[i] >= (char)'[' && (char)text[i] <= (char)'`') { lastWut = &lastSC2; 	 currentCell = 3; }
		else if ((char)text[i] >= (char)'{' && (char)text[i] <= (char)'~') { lastWut = &lastSC3; 	 currentCell = 4; }
			
		// grab the distance from the last cell to the current so we know how many cells to move
		distance = lastCell - currentCell;
			
		// here is where we move the cells
		if (distance > 0)		
			push = '<';
		else if (distance < 0)
		{
			push = '>';
			distance = -distance;
		}
		
		// now we set the cell for next loop!
		lastCell = currentCell;
		
		// now we print out the push which is how many cells we move over
		if (distance != 0)
		{
			for (j = 0; j < distance; j++)
				printf("%c", push);
		}
			
		// now we're setting distance for character distance
		distance = (int)(*lastWut - text[i]);
			
		// again we're setting push
		if (distance > 0)			
			push = '-';
		else if (distance < 0)
		{
			push = '+';
			distance = -distance;
		}
		
		// and now we print out the push
		if (distance != 0)
		{
			for (j = 0; j < distance; j++)
				printf("%c", push);
		}
		
		// now that we're at our character we print a period which is the print character in bf
		printf(".");
		// we set our lastWut pointer to the last character so it changes our last for the cell set
		*lastWut = text[i];
	}
	
	printf("\n");

	return 0;
}
