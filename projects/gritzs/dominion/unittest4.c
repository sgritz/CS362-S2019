/*-----------------------------------------------------------------------------------
 *Assignment 3: Unit Test 4 - playCouncilRoom() Test
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
	int otherPlayer = 1; 
	int cardDiffP1;
	int cardDiffP2;
	int buyDiff;
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing playCouncilRoom(): \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	playCouncilRoom(currPlayer, &test);
	
	//hand count +4
	cardDiffP1 = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiffP1 != 4){
		printf("Incorrect number of cards added to hand. Test failed. \n");
	}
	
	//Other player handCount +1
	cardDiffP2 = test.handCount[otherPlayer] - game.handCount[otherPlayer];
	
	if (cardDiffP1 != 1){
		printf("Incorrect number of cards added to other player's hand. Test failed. \n");
	}
	
	buyDiff = test.numBuys - game.numBuys;
	if (buyDiff != 1){
		printf("Incorrect number of Buys. Test failed. \n");
	}
 }
 
 //Card outcome: +4 cards, +1 buy, +1 each other player draws a card
 //Test 1: currPlayer handcount +4
 //Test 2: currPlayer numBuys +1
 //Test 3: otherPlayer handCount + 1
