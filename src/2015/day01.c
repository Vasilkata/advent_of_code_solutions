#include<stdio.h>
#include<stdbool.h>

int main(int argc, char *argv[]) {
	//Print an error if the user put 2 or more arguments
	if(argc > 2) {
		printf("Error! Usage: <input.txt>\n");
		return 1;
	}

	//Open the file in reading mode
	FILE *file = fopen(argv[1], "r");
	//Print an error if the file can't be opened
	if(file == NULL) {
		printf("Error! Couldn't open file!\n");
		return 1;
	}

	//Create all variables needed
	char c;							//a character for the command
	int floor = 0;					//which floor Santa is on
	int position = 0;				//the index of the character
	bool entered_basement = false;	//a bool for if Santa has entered the basement yet

	//Read every character in the file till we encounter the EOF character
	while((c = fgetc(file)) != EOF) {
		//Every time we see '(' we increment by one
		if(c == '(') {
			floor++;
			position++;
		}
		//Every time we see ')' we decrease by one
		else if(c == ')') {
			floor--;
			position++;
			//Check if it's the first time Santa enters the basement
			if(!entered_basement && floor == -1) {
				printf("Entered the basement at position %d\n", position);
				entered_basement = true;
			}
		}
	}

	//Print the floor Santa is on
	printf("Santa ended on floor %d\n", floor);

	//Close the file
	fclose(file);

	return 0;
}
