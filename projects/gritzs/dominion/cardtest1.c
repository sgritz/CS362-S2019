/*----------------------------------------------------------------------------
 *Assignment 3: Card Test 1 - Adventurer
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
	
	printf("Testing Adventurer: \n");
	
	memcpy(&test, &game, sizeof(struct gameState));
	
	cardEffect(great_hall, 0, 0, 0, &test, 0, currPlayer);
	
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	
	if (cardDiff != 2){
		printf("Incorrect number of cards added to hand. Test failed. \n");
	}
	
	coinDiff = test.coins[currPlayer] - game.coins[currPlayer];
	
	if (coinDiff < 2){
		printf("Insufficient number of treasures drawn. Test failed. \n");
	}		
 }
 
 //CARD OUTCOMES: draw cards until 2 treasures, add 2 treasures to hand
 //TESTs NEEDed:
 //1 - deck has copper, silver, gold and handCountDiff < 2
 //2 - if deck = 0 and discardDiff = 0, error //making sure discard working
