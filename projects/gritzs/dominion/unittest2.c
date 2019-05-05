/*----------------------------------------------------------------------------
 *Assignment 3: Unit Test 2 - playFeast()
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
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int handValGame = 0;
	int handValTest = 0;
	int choice1 = 0;
	struct gameState game, test;
	int err = 0;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing playFeast(): \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	playFeast(currPlayer, &test, choice1);
	
	//Test 1: Testing correct number of cards in hand at end of turn
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 0){
		printf("Incorrect number of cards added to hand. Test failed. \n");
		err++;
	}	

	
	//Test 2: Total value of hand before and after playFeast called. If not increased by 1, fails
	for (i=0; i < test.handCount[currPlayer]; i++){
		handValTest = getCost(test.hand[currPlayer][i]);
	}
	
	for (i=0; i < game.handCount[currPlayer]; i++){
		handValGame = getCost(game.hand[currPlayer][i]);
	}
	
	if (handValTest-handValGame != 1){
		printf("Invalid card drawn (cost). Test failed. \n");
		err++;
	}

	if(err == 0){
		printf("All tests passed. \n");
	} 
}
 
 
