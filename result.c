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

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int i) 
{
	int j;
	cardsum[i]=0;
	for(j=0;j<=cardcnt;j++)
	{
		cardsum[i] +=cardhold[i][j]
	}
	if(cardsum[i]==21)
	{
		dollar[i] = dollar[i] + bet[i] * 2;
		printf("          ::: Black Jack!congratulation, you win!! --> +$%d ($%d)\n", 2*bet[i], dollar[i]);
		break;
	}
	else if(cardsum[i]>=21)
	{
		dollar[i] = dollar[i] - bet[i];
		printf("          ::: DEAD (sum:%d) --> -$%d ($%d)", cardsum[i], bet[i], dollar[i]);
		break;
	}
	else
	getAction(int i);                   //GO? STOP? ::: getAction()
}

int checkResult(int gameEnd) 
{
	printf(" -------------------- ROUND %d result ....\n", roundIndex);
	for(i=1;i<=n_user;i++)
	{
		if (i==1)
		{
			printf("   -> your result :");
		}
		else
		{
			printf("   -> %d'th player's result :", i-1);
		}
		
		
		if (cardSum[i] == 21)
		{
			printf("BlackJack! win ($%d)\n", dollar[i]);
		}
		else if(cardSum[i] > 21)
		{
			printf("lose due to overflow! ($%d)\n", dollar[i]);
			if(dollar[i]=0)
			{
				gameEnd++;
			}
		}
		else
		{
			if(cardsum[0]==21)
			{
				dollar[i] = dollar[i] - bet[i];
				printf("lose! (sum:%d) --> $%d\n", cardsum[i], dollar[i]);
				if(dollar[i]=0)
			{
				gameEnd++;
			}
			}
			if(cardsum[0]>21)
			{
				dollar[i] = dollar[i] + bet[i];
				printf("win! (sum:%d) --> $%d\n", cardsum[i], dollar[i]);
			}
			else
			{
				if(cardsum[i]>=cardsum[0])
				{
					dollar[i] = dollar[i] + bet[i];
					printf("win! (sum:%d) --> $%d\n", cardsum[i], dollar[i]);
				}
				else
				{
					dollar[i] = dollar[i] - bet[i];
					printf("lose! (sum:%d) --> $%d\n", cardsum[i], dollar[i]);
					if(dollar[i]=0)
			{
				gameEnd++;
			}
				}
			}
		}
	}
}

int checkWinner() 
{
	printf(" ----------------------------\n");
	printf(" ----------------------------\n");
	printf(" ----------------------------\n");
	printf("game end! your money : $ %d, player's money : $ %d $ %d $ %d $ %d\n", dollar[1], dollat[2]. dollar[3], dollar[4], dollar[5]);
	int i;
	int maxdollar;
	maxdollar = dollar[1];
	for(i=1;i<=n_user;i++)
	{
		if(maxdollar < score[i])
		{
			maxdollar = dollar[i];
			if(i=1)
			{
				printf("you are win.");
			}
			else
			{
				printf("player %d is win", i-1);
			}
		}
	}
}



