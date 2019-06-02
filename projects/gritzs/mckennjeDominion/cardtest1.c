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
	int seed = 1000;
	int numPlayers = 2;
	int currPlayer = 0;
	int cardDiff;	
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0; 
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState game, test;
	int err = 0; //error counter
	
	//Initialize game
	initializeGame(numPlayers, kingdom, seed, &game);
	
	printf("Testing Adventurer: \n");
					
	memcpy(&test, &game, sizeof(struct gameState));
	adventurerCardEffect(&test);	
	
	//Test 1: number of cards added to hand +2
	cardDiff = test.handCount[currPlayer] - game.handCount[currPlayer];
	if (cardDiff != 1){
		printf("Incorrect number of cards added to hand. Test failed. \n");
		err++;
	}
	
	//Test 2: Checking if last 2 cards added to hand are treasure
	if((test.hand[currPlayer][test.handCount[currPlayer]] != copper || test.hand[currPlayer][test.handCount[currPlayer]] != silver ||test.hand[currPlayer][test.handCount[currPlayer]] != gold) &&(test.hand[currPlayer][test.handCount[currPlayer]-1] != copper || test.hand[currPlayer][test.handCount[currPlayer]-1] != silver || test.hand[currPlayer][test.handCount[currPlayer]-1] != gold)){
		printf("One of your last two cards is not a treasure. Test failed. \n");
		err++;
	}
	//Pass/Fail
	if(err == 0){
		printf("All tests passed. \n");
	}
}

