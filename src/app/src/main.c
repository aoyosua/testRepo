#include <stdio.h>

#include "die.h"

int main(int argc, char **argv)
{
	Die_t *testDie = createDie(6);
	printf("rolled a %d\n", testDie->Roll(testDie));
	return 0;
}


