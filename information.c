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
int Ace = 0;


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
int roundIndex;


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) 
{
	if (cardnum == 0 || cardnum == 13 || cardnum == 26 || cardnum == 39 )
	{
		printf("\na player-picked card : A");
        do 
		{
            printf("\nDo you want to use A as 1? Do you want to use it as 11?");
			printf("\n(Enter 1 if you want to use it as 1 or enter 0 if you want to use it as 11.)");
            scanf("%d", &Ace);
        }
		while (Ace != 1 && Ace != 0);
        if (Ace == 1) 
		{
        	CardTray[cardnum] = 1;            //Use A as 1
        }
        else if (Ace == 0)
		{
        	CardTray[cardnum] = 11;           //Use A as 11
		}
   	}
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) 
{
	if (cardnum >= 1 && cardnum <= 9)
	{
		printf("HRT%i\n", CardTray[cardnum]);
	}	
	else if (cardnum >= 14 && cardnum <= 22)
	{
		printf("SPD%i\n", CardTray[cardnum]);
	}
	else if (cardnum >= 27 && cardnum <= 35)
	{
		printf("CLV%i\n", CardTray[cardnum]);
	}
	else if (cardnum >= 40 && cardnum <= 48)
	{
		printf("DIA%i\n", CardTray[cardnum]);
	}
	else if (cardnum == 0)
	{
		printf("HRTAce\n");
	}
	else if (cardnum == 13)
	{
		printf("SPDAce\n");
	}
	else if (cardnum == 26)
	{
		printf("CLVAce\n");
	}
	else if (cardnum == 39)
	{
		printf("SPDAce\n");
	}
	else if (cardnum == 10)
	{
		printf("HRTKing\n");
	}
	else if (cardnum == 11)
	{
		printf("HRTQueen\n");
	}
	else if (cardnum == 12)
	{
		printf("HRTJack\n");
	}
	else if (cardnum == 23)
	{
		printf("SPDKing\n");
	}
	else if (cardnum == 24)
	{
		printf("SPDQueen\n");
	}
	else if (cardnum == 25)
	{
		printf("SPDJack\n");
	}
	else if (cardnum == 36)
	{
		printf("CLVKing\n");
	}
	else if (cardnum == 37)
	{
		printf("CLVQueen\n");
	}
	else if (cardnum == 38)
	{
		printf("CLVJack\n");
	}
	else if (cardnum == 49)
	{
		printf("DIAKing\n");
	}
	else if (cardnum == 50)
	{
		printf("DIAQueen\n");
	}
	else if (cardnum == 51)
	{
		printf("DIAJack\n");
	}
}


