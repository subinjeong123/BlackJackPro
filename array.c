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
int cardIndex = 0;


//player info
int n_user;									//number of users


//card array controllers -------------------------------

//mix the card sets and put in the array
void mixCardTray(int CardTray[N_CARDSET*N_CARD])
{
	int w = 0,r = 0;
	int i = 0;
	for(i = 0; i < 52; i++) 
	{
		swit[i] = false;
	}

	srand(time(NULL));
	while(w < 52) 
	{
		r = rand() % 52;
		if(swit[r] == false) 
		{
			swit[r] = true;
			CardTray[w] = r + 1;
			w++;
		}
	}
}

//get one card from the tray
int pullCard(int cardresult)
{
	int i;
	cardresult = swit[i];
	i++;
	cardIndex++;
	if(cardIndex>=52)
	{
		gameEnd++;
	}
	return cardresult;
}


