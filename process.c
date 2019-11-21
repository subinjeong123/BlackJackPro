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


//playing game functions -----------------------------

//player settiing
int configUser(void) 
{
	do
	{
		printf("Input the number of players (MAX:5):");
		scanf("%d", &n_user);
	}		
	while(n_user>N_MAX_USER);
	
	return n_user;
}


//betting
int betDollar(int i) 
{
	printf("------------------------------------------------\n");
	printf("------------ ROUND %d (cardIndex:%d)--------------------------\n", roundIndex, cardIndex ); //좀있다가 메인함수로 옮기기//
	printf("------------------------------------------------\n\n");
	printf(" ------- BETTING STEP -------\n");
	printf("  -> your betting (total:$%d) :  \n", dollar[0]);
	
	scanf("%d", &bet[1]);
	if (bet[1]>dollar[1])
	{
		printf("  -> you only have $50! bet again");
		do
		{
			printf("  -> your betting (total:$%d) :  ");
			scanf("%d\n", &bet[1]);
		}		
		while(bet[1]>dollar[1]);
	}
	for(i = 2; i < n_user; i++)
	{
		int randbet[i];
		randbet[i] = rand() % 9 + 1;
		if (randbet[i] > dollar[i])
		{
			bet[i] = dollar[i];
		}
		else
		{
			bet[i] = randbet[i];
		}
	}
}


//offering initial 2 cards
void offerCards()
{
	int i;
	//1. give two card for each players
	for (i=1;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[0][0] = pullCard();
	cardhold[0][1] = pullCard();
	
	return;
}


//print initial card status
void printCardInitialStatus(void) 
{
	printf(" ----------- CARD OFFERING ---------------\n");
	printf(" --- server      : ");
	printf("X ");
	printCard(int cardhold[0][1]);
	printf("   -> you        : ");
	printCard(int cardhold[1][0])
	printCard(int cardhold[1][1])
	for(i=2;i<n_user;i++)
	{
	
		printf("   -> player %d   :", i)
		printCard(int cardhold[i][0])
		printCard(int cardhold[i][0])
		print("\n")
	}
}


int getAction(int i) 
{
	if(i=1)
	{
		printf("        ::: Action? (0 - go, others - stay) :0");
		int gostop;
		scanf("%d", &gostop);
		if(gostop=0)
		{
			cardhold[i][cardcnt] = pullCard();
		}
		else
		{
			break;
		}
	}
	else
	{
		if(cardsum[i]>=N_MAX_GO)
		{
			printf("        ::: STAY!\n");
			break;
		}
		else
		{
			printf("        ::: GO!\n");
			cardhold[i][cardcnt] = pullCard();
		}
		
	}
}


void printUserCardStatus(int user, int cardcnt) 
{
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}



