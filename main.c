#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
    1,2,3,4,5,6,7,8,9,10,10,10,10,
    1,2,3,4,5,6,7,8,9,10,10,10,10,
    1,2,3,4,5,6,7,8,9,10,10,10,10 };           //Leaving the role of the getCardnum function out to see if the program starts well. We're going to put it inside when it goes any further.
int swit[52];   
int cardresult;    
int Ace = 0;
int cardIndex = 0;


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
int roundIndex;


//play yard information
int cardhold[N_MAX_USER][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag


int main(int argc, char *argv[]) 
{
	int roundIndex = 0;
	int max_user;
	int i;
	int bet[i], dollar[i], cardSum[i];
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	getCardNum();
	mixCardTray();



	//Game start --------
	do 
	{	
		betDollar(int i);
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0;i<=n_user;i++) //each player
			{		
				printUserCardStatus(int user, int cardcnt)                   //print current card status printUserCardStatus();
				calcStepResult(int i);                                       //check the card status ::: calcStepResult()
			}
		
		//result
		checkResult(int gameEnd);
		roundIndex++;
	} 
	while (gameEnd == 0);
	
	checkResult();
	
	checkWinner();
	
	
	return 0;
}
