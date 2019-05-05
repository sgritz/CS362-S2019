/*----------------------------------------------------------------------------
 *Assignment 3: Unit Test 1 - playAdventurer()
 *Author: Stephanie Gritz
 *OSU CS362-400
 *May 5, 2019
 *Prof. Roberts
 *
 *Created using templated version of demo file provided to class for this use
 *----------------------------------------------------------------------------
 *Note to self: for card test? need to test what happens if yoiu only find `
 */
 
 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
 #include "rngs.h"
 
 int main(){
	int i;
	int seed = 1000;
	int numPlayers = 2;
	int currPlayer = 0;
	int cardDiff;
`	int coinDiff;	
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int temp[MAX_HAND];
	struct gameState game, test;
	int err = 0;  //if zero at end, passed all tests
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing playAdventurer(): \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	playAdventurer(currPlayer, &test);
	
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff < 1){
		printf("Too few cards added to hand. Test failed. \n");
	}
	
	if (cardDiff >= 3){
		printf("Too many cards added to hand. Test failed. \n");
	}
		
 }
