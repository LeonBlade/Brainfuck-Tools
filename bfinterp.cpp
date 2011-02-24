/*
 * bfinterp.cpp
 * pass in the bf code you want to exectute works with unix pipe which is fun!
 *
**/
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	// our variables!
	// k is for the code, b is what is interpreted is pointed to by x and y is for the loops
	// we're also using a size of 30000 here feel free to make this dynamic or whatever
	char *k;
	unsigned char b[30000] = {0};
	unsigned char *x = b;
	std::stack<char*> y;
	
	// allocate some memory for k
	k = (char*)malloc((char)30000);
	
	// if we aren't passing it in with the command we grab from stdin go pipe!
	if (argc < 2)
		fgets(k, 30000, stdin);
	// if we are passing in our bf code then copy the memory into k
	else if (argc == 2)
		memcpy(k, argv[1], strlen(argv[1]));
	
	// going over our pointer for different symbols
	while(*k)
	{
			 if(*k == '+') ++*x;
		else if(*k == '-') --*x;
		else if(*k == '>') ++x;
		else if(*k == '<') --x;
		else if(*k == ',') *x = std::cin.get(); 	// , grabs characters
		else if(*k == '.') std::cout << *x; 		// . prints characters
		else if(*k == '[') y.push(k + 1);			// start loop
		else if(*k == ']')							// end loop
		{
			// go stacks!
			if (*x) 
			{ 
				k = y.top(); 
				continue; 
			}
			else 
				y.pop();
		}
		// make sure to flush after you go to the bathroom
		fflush(stdin);
		k++;
	}
	std::cout << "\n";
	
	return 0;
}
