/************************************************************************
 * Assignment 4 - randomtest2 - Great Hall (+1 card, +1 action, +1 score)
 * Author: Stephanie Gritz
 * OSU CS362-400
 * Prof. Roberts
 * May 19, 2019
 *************************************************************************/


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
	int numActionsPre;
	int numActionsPost;
	int handpos = 0;
	int handPassed = 0, deckPassed = 0, actPassed = 0;
	int deckFailed = 0, handFailed = 0, actFailed = 0;
 
	

	//Tests
	printf("Testing Great Hall Card: \n");

	for (i = 0; i <1000; i++){		//test with some randomized conditions 1000 times
		printf("Test %d\n", i);
		numPlayers = rand() % 6 + 2;	//rand num players 2-5
		
		initializeGame(numPlayers,kingdom, seed, &game);
	
		game.deckCount[player] = rand()%30 + 1;	//randomize deckCount between 1 and 30
		deckPreCount = game.deckCount[player];
		
		game.handCount[player] = rand() % 6 + 1; //random num cards in hand 1-5
		handPreCount = game.handCount[player];
		
		game.numActions = rand()%4 +1; //random num actions 1 to 4
		numActionsPre = game.numActions;

		playGreatHall(player, &game, handpos);
		
		deckPostCount = game.deckCount[player];
		handPostCount = game.handCount[player];
		numActionsPost = game.numActions;
		
		if (deckPostCount-deckPreCount != 1){	//deck count should decrease by 1
			printf("Deck count test passed \n");
			deckPassed++;
		}	
		else{
			printf("Deck count test failed \n");
			deckFailed++;		
		}
		
		if (handPostCount-handPreCount != 1){	//deck count should decrease by 1
			printf("Hand count test passed \n");
			handPassed++;
		}	
		else{
			printf("Hand count test failed \n");
			handFailed++;		
		}
		
		if (numActionsPost - numActionsPre !=0){//action count should increase by 1
			printf("Action count test passed \n");
			actPassed++;
		}
		else{
			printf("Action count test failed \n");
			actFailed++;
		}
	}
	
	printf("Hand tests passed: %d\n", handPassed);
	printf("Hand tests failed: %d\n", handFailed);
	printf("Deck tests passed: %d\n", deckPassed);
	printf("Deck tests failed: %d\n", deckFailed);
	printf("Actions tests passed: %d\n", actPassed);
	printf("Action tests failed: %d\n", actFailed);

	return 0;
}
