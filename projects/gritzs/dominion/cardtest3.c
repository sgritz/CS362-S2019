/*----------------------------------------------------------------------------
 *Assignment 3: Card Test 3 - Village
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
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0; 
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	int err = 0;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing Village: \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	cardEffect(village, choice1, choice2, choice3, &test, handpos, &bonus);

	//Test 1: Check if hand +1 card
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 0){
		printf("Incorrect number of cards added to hand. Test failed. \n");
		err++;
	}
	
	//Test 2: Check if Actions +2	
	actDiff = test.numActions - game.numActions;
	
	if (actDiff != 1){
		printf("Incorrent number of actions added. Test failed. \n");
		err++;
	}	

	//Pass/Fail
	if(err == 0){
		printf("All tests passed. \n");
	}
 }
