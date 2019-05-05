/*----------------------------------------------------------------------------
 *Assignment 3: Unit Test 3 - playGreatHall()
 *Author: Stephanie Gritz
 *OSU CS362-400
 *May 5, 2019
 *Prof. Roberts
 *
 *Created using templated version of demo file provided to class for this use
 *----------------------------------------------------------------------------
 */
 
 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
 #include "rngs.h"
 
 int main(){
	int seed = 1000;
	int numPlayers = 2;
	int currPlayer = 0;
	int cardDiff;	
	int actDiff;
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	int err = 0;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing playGreatHall(): \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	playGreatHall(currPlayer, &test);
	
	//Hand count increased by +1?
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 1){
		printf("Incorrect number of cards added to hand. Test failed. \n");
		err++;	
	}
	
	//Actions increased by +1
	actDiff = test.numActions - game.numActions;
	if (actDiff != 1){
		printf("Incorrect number of actions. Test failed. \n");
		err++;
	}
	
	//Pass/fail?
	if (err == 0){
		printf("All tests passed. \n");
	} 
} 
