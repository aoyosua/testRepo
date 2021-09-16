#ifndef DICE_H
#define DICE_H

// includes
#include <stdbool.h>
#include <stdint.h>

// defines
#define MAX_NUM_ATTK_DICE 3
#define MAX_NUM_DEF_DICE 2

// constants
bool areNukesAllowed;

// data
bool diceInitialized;
int8_t attackerDice[MAX_NUM_DEF_DICE];
int8_t numOfActiveAttackingDice;
int8_t defenderDice[MAX_NUM_ATTK_DICE];
int8_t numOfActiveDefendingDice;


// function prototypes
void initializeDice();
void printDiceValues(bool showRawData);
void rollDice(int8_t attackerDiceNumber, int8_t defenderDiceNumber);
int16_t rollDie(int8_t numSidesOnDie);
int compareDice(const void *die1, const void *die2);
void sortDice();


#endif