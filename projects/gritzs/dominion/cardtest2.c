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
	int i;
	int seed = 1000;
	int numPlayers = 2;
	int currPlayer = 0;
	int cardDiff;	
	int choice1 = 0, choice2 = 0, choice 3 = 0, handpos = 0; 
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing Smithy: \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	cardEffect(smithy, choice1, choice2, choice3, &test, handpos, currPlayer);
	
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 3){
		printf("Incorrect number of cards added to hand. Test failed. \n");
	}	
 }
 
 //CARD OUTCOME: +3 cards to hand
 //TESTS NEEDED
 //1 - handcount diff  = 3
 //2 - discard = 0
 //3 - if deck < 3 when cardEffect called
