#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> 
#include <stdbool.h>

#include "dice.h"

void initializeDice()
{
	// Use current time as seed for random generator
	srand((unsigned)time(NULL));
	
	diceInitialized = true;
}

void printDiceValues(bool showRawData)
{
	// Loop through the array of attacker's dice.
	printf("attacker: [");
	if (showRawData)
	{
		for(int dieNum = 0; dieNum < MAX_NUM_ATTK_DICE; dieNum++)
		{
			// If not the last die than add a comma afterwards.
			if (dieNum < (MAX_NUM_ATTK_DICE - 1))
			{
				printf("%d,", attackerDice[dieNum]);
			}
			// If the die is the last one than put a close bracket afterwards.
			else if ((attackerDice[dieNum] == 0) || (dieNum == (MAX_NUM_ATTK_DICE - 1)))
			{
				printf("%d]\n", attackerDice[dieNum]);
			}
		}
	}
	else
	{
		for(int dieNum = 0; dieNum < numOfActiveAttackingDice; dieNum++)
		{
			// If not the last die than add a comma afterwards.
			if (dieNum < (numOfActiveAttackingDice - 1))
			{
				printf("%d,", attackerDice[dieNum]);
			}
			// If the die is the last one than put a close bracket afterwards.
			else if ((attackerDice[dieNum] == 0) || (dieNum == (numOfActiveAttackingDice - 1)))
			{
				printf("%d]\n", attackerDice[dieNum]);
			}
		}
	}
	
	// Loop through the array of defender's dice.
	printf("defender: [");
	if (showRawData)
	{
		for(int dieNum = 0; dieNum < MAX_NUM_DEF_DICE; dieNum++)
		{
			// If not the last die than add a comma afterwards.
			if (dieNum < (MAX_NUM_DEF_DICE - 1))
			{
				printf("%d,", defenderDice[dieNum]);
			}
			// If the die is the last one than put a close bracket afterwards.
			else if ((defenderDice[dieNum] == 0) || (dieNum == (MAX_NUM_DEF_DICE - 1)))
			{
				printf("%d]\n", defenderDice[dieNum]);
			}
		}
	}
	else
	{
		for(int dieNum = 0; dieNum < numOfActiveDefendingDice; dieNum++)
		{
			// If not the last die than add a comma afterwards.
			if (dieNum < (numOfActiveDefendingDice - 1))
			{
				printf("%d,", defenderDice[dieNum]);
			}
			// If the die is the last one than put a close bracket afterwards.
			else if ((defenderDice[dieNum] == 0) || (dieNum == (numOfActiveDefendingDice - 1)))
			{
				printf("%d]\n", defenderDice[dieNum]);
			}
		}
	}
}

void rollDice(int8_t attackerDiceNumber, int8_t defenderDiceNumber)
{
	// Verify that a valid number of dice is passed in to prevent running over the end of the array.
	if (attackerDiceNumber <= MAX_NUM_ATTK_DICE && defenderDiceNumber <= MAX_NUM_DEF_DICE)
	{
		// Roll the attacker's dice, and fill out 0s for the rest of the arrary if less than the max was specified.
		for(int dieNum = 0; dieNum <= MAX_NUM_ATTK_DICE; dieNum++)
		{
			if (dieNum < attackerDiceNumber)
			{
				attackerDice[dieNum] = rollDie(6);
				
			}
			else
			{
				attackerDice[dieNum] = 0;
			}
		}
		
		// Roll the defender's dice, and fill out 0s for the rest of the arrary if less than the max was specified.
		for(int dieNum = 0; dieNum <= MAX_NUM_DEF_DICE; dieNum++)
		{
			if (dieNum < defenderDiceNumber)
			{
				defenderDice[dieNum] = rollDie(6);
			}
			else
			{
				defenderDice[dieNum] = 0;
			}
		}
	}
	
	// Set the number of active dice so printing logic is simpler.
	numOfActiveAttackingDice = attackerDiceNumber;
	numOfActiveDefendingDice = defenderDiceNumber;
}

int16_t rollDie(int8_t numbersOnDie)
{
	int16_t dieValue = rand();
	dieValue = (dieValue % numbersOnDie) + 1;
	
	return dieValue;
}

int compareDice(const void *die1ptr, const void *die2ptr)
{
	int8_t *die1 = (int8_t *)die1ptr;
	int8_t *die2 = (int8_t *)die2ptr;
	
	return *die1 < *die2;
}

void sortDice()
{
	// Sort the attackers dice.
	qsort(attackerDice, 3, sizeof(attackerDice[0]), compareDice);
	
	// Sort the defenders dice.
	qsort(defenderDice, 2, sizeof(defenderDice[0]), compareDice);
}
