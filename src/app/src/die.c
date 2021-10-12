#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

#include "die.h"

Die_t *createDie(const int8_t numbersOnDie)
{
	// Use current time as seed for random generator
	srand((unsigned)time(NULL));
	
	Die_t *self = malloc(sizeof(Die_t));
	
	self->numbersOnDie = numbersOnDie;
	
	self->Roll = &roll;
	
	return self;
}

const int8_t roll(void *self)
{
	int16_t dieValue = rand();
	dieValue = (dieValue % SELF->numbersOnDie) + 1;
	
	return dieValue;
}



