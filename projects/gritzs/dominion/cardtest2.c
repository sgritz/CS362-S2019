/*----------------------------------------------------------------------------
 *Assignment 3: Card Test 2 - Smithy
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
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0; 
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	int err = 0;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing Smithy: \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	cardEffect(smithy, choice1, choice2, choice3, &test, handpos, &bonus);

	//TEST 1: Confirm difference in handcount is +3 (when deck has available cards)
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 2 && test.deckCount[currPlayer] != 0){ //diff is 2, -1 discard +3 drawn
		printf("Incorrect number of cards added to hand. Test failed. \n");
		err++;
	}
	//Pass/Fail	
	if(err == 0){
	printf("All tests passed. \n");
	}
 }
	
