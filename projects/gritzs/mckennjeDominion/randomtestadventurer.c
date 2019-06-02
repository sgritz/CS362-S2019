/**********************************************************************
 * Assignment 4 - randomtestadventurer - Adventurer
 * Author: Stephanie Gritz
 * OSU CS362-400
 * Prof. Roberts
 * May 19, 2019
 **********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int seed = 1000;
	int player = 0;
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, cutpurse, great_hall};
	struct gameState game;

	int i;
	int numPlayers;
	int deckPreCount;
	int deckPostCount;
	int handPreCount;
	int handPostCount;

	int handPassed = 0, deckPassed = 0;
	int deckFailed = 0, handFailed = 0;

	//Tests
	printf("Testing Adventurer Card: \n");

	for (i = 0; i <1000; i++){		//test with some randomized conditions 1000 times
		numPlayers = rand() % 6 + 2;	//rand num players 2-5
		
		initializeGame(numPlayers,kingdom, seed, &game);
	
		game.deckCount[player] = rand()%30 + 1;	//randomize deckCount between 1 and 30
		deckPreCount = game.deckCount[player];
		
		game.handCount[player] = rand() % 6 + 1; //random num cards in hand 1-5
		handPreCount = game.handCount[player];

		adventurerCardEffect(&game);
		
		deckPostCount = game.deckCount[player];
		handPostCount = game.handCount[player];
		
		if (deckPreCount-deckPostCount >= 1){	//deck count should decrease by 1
			printf("Deck count test passed \n");
			deckPassed++;
		}	
		else{
			printf("Deck count test failed \n");
			deckFailed++;		
		}
		
		if (handPostCount-handPreCount != 2){	//hand count should increase by 1
			printf("Hand count test passed \n");
			handPassed++;
		}	
		else{
			printf("Hand count test failed \n");
			handFailed++;		
		}
	}
	
	printf("Hand tests passed: %d\n", handPassed);
	printf("Hand tests failed: %d\n", handFailed);
	printf("Deck tests passed: %d\n", deckPassed);
	printf("Deck tests failed: %d\n", deckFailed);
	
	return 0;
}	
