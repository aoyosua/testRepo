#ifndef DIE_H
#define DIE_H

#include <stdint.h>

#include "diePrivate.h"

typedef struct
{
	int8_t numbersOnDie;
	const int8_t (*Roll)(void *self);
} Die_t;

Die_t *createDie(const int8_t numbersOnDie);

#endif