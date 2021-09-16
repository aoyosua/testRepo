#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "argumentProcessor.h"

bool validateArguments(int argc, char **argv)
{
	bool isValidArguments;
	
	// Check to make sure the only argument is -r.
	if (argc == 1 )
	{
		fprintf(stderr, "Error in %s: enter a valid argument.\n", __func__);
		isValidArguments = false;
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1],"-r") != 0)
		{
			fprintf(stderr, "Error in %s: invalid argument.\n", __func__);
			isValidArguments = false;
		}
		else
		{
			isValidArguments = true;
		}
	}
	else
	{
		fprintf(stderr, "Error in %s: too many arguments.\n", __func__);
		isValidArguments = false;
	}
	
	return isValidArguments;
}