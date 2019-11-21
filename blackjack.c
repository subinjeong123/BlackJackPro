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
int roundnum;


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag


//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) 
{
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


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
	printf("------------ ROUND %d (cardIndex:%d)--------------------------\n", roundnum, cardIndex ); //좀있다가 메인함수로 옮기기//
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


void printUserCardStatus(int user, int cardcnt) 
{
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
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




int TestHalt()
{
	cardcnt++;
	cardindex = cardindex + 1;
	if(cardIndex>=N_CARDSET*N_CARD)
	printf("card ran out of the tray!! finishing the game....")
	break;
}



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
	
}

int checkWinner() 
{
	
}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	getCardNum();
	mixCardTray();



	//Game start --------
	do {
		
		betDollar(int i);
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0;i<=n_user;i++) //each player
		{
			while () //do until the player dies or player says stop
			{
				printUserCardStatus(int user, int cardcnt)                   //print current card status printUserCardStatus();
				calcStepResult(int i);                                       //check the card status ::: calcStepResult()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult(int gameEnd);
	} while (gameEnd == 0);
	
	checkResult();
	
	checkWinner();
	
	
	return 0;
}
