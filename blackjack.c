#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX_USER			5
#define N_DOLLAR			50



//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users

//it's role is instead of scanf function.
int getIntegerInput(void) 
{
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

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

int main(void)
{
	int i;
	i = configUser();

}
