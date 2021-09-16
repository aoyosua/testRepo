#include <stdio.h>
#include <stdlib.h>

#include "argumentProcessor.h"
#include "dice.h"

int main(int argc, char **argv)
{
	bool isValidArguments = validateArguments(argc, argv);
	
	if (isValidArguments)
	{
		// Roll and print the dice.
		initializeDice();
		rollDice(2, 1);
		sortDice();
		printDiceValues(false);
	}
	else
	{
		exit(-1);
	}
	return 0;
}



