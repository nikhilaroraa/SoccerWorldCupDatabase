#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//included needed header file required to use functions from different files
#include "worldcup_player.h"
//#define used to set maximum character length of player name and club to 50 characters
#define NAME_LEN2 50

//Read line function created and used when entering player name and club to get rid of extra characters
int read_line2(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()));
    while (ch != '\n' && ch != EOF)
    {
        if (i < n)
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

//This structure outlines the Players and the needed details for each portion of the Player information
struct Player
{
	int code;
	char name[NAME_LEN2+1];
	int age;
	char club[NAME_LEN2+1];
	struct Player *next;
};

//Head structure node
struct Player *worldcup = NULL;

//This structure is used to find the corresponding player with the player code and perform different functions
struct Player *findPlayer(int code)
{
	struct Player *ptr;
	for (ptr = worldcup; ptr != NULL && code > ptr->code; ptr = ptr->next);
	if (ptr != NULL && code == ptr->code)
		return ptr;
	return NULL;
}

//This method is created to input details of each player by taking a reference of the Player structure then taking data from the user into the structure
void insertPlayer()
{
	struct Player *currentNode, *previousNode, *newNode;

	newNode = malloc(sizeof(struct Player));

	if (newNode == NULL) {
	//if statement created to check if the database is full and return an error message if it is
		printf("Database is full, no new teams can be added.\n");
		return;
	}

	printf("Enter player code: ");
	//Prompt for the user to enter the player code
	scanf("%d", &newNode->code);
	for (currentNode = worldcup, previousNode = NULL; currentNode != NULL && newNode->code > currentNode->code; previousNode = currentNode, currentNode = currentNode->next);
	//for loop used to check if the code already exists in the database
	if (currentNode != NULL && newNode ->code == currentNode->code){
		printf("Player already exists. \n");
		//Prints an error message and frees up node allocated memory while returning to initial operation code prompt
		free(newNode);
		return;
	}
	printf("Enter player name: ");
	//Prompt for user to enter the player name
	read_line2(newNode->name, NAME_LEN2);
	//Read line function called when entering the name value to properly interpret characters entered
	printf("Enter player age: ");
	//Prompt for user to enter the player age
	scanf("%d", &newNode->age);
	if (newNode->age < 17 || newNode->age > 99)
	//if statement created to check if the number entered is within the given range
	{
		printf("Not a valid age\n");
		//Prints an error message and frees up node allocated memory while returning to initial operation code prompt if a valid age is not selected
		free(newNode);
		return;
	}
	printf("Enter player club: ");
	//Prompt for user to enter the player club
	read_line2(newNode->club, NAME_LEN2);
	//Read line function called when entering the club value to properly interpret characters entered
	newNode->next = currentNode;

	if (previousNode == NULL)
	//if statement used to set the worldcup node to the newNode value if the previousNode is equal to NULL
		worldcup = newNode;
	else
		previousNode->next = newNode;
}

//This method is used to search for a player in the database if selected by the user
void searchPlayer()
{
	int code;
	struct Player *ptr;
	printf("Enter player code: ");
	//Print statement used to prompt the user to enter the player code
	scanf("%d", &code);
	ptr = findPlayer(code);
	if (ptr != NULL) {
	//if statement used to check if a corresponding player code exists and print the information of the player
		printf("%-25s %-25s %-25s %-25s\n", "Player Code", "Player Name", "Player Age", "Player Club");
		//Print statement used to print the headers
        printf("%-25d %-25s %-25d %-25s\n", ptr-> code, ptr->name, ptr->age, ptr->club);
        //Print statement used to print the player details
	}
	else
	//else statement used to print error message if a corresponding player code entered does not exist
		printf("Player does not exist. \n");
}

//This method is used to update a player's details in the database if the user selects this option
void updatePlayer()
{
	int code;
	struct Player *ptr;
	printf("Enter player code: ");
	//Print statement used to prompt the user to enter the player code
	scanf("%d", &code);
	ptr = findPlayer(code);
	if (ptr != NULL)
	{
	//if statement used to check if a corresponding player code exists and update the information of the player
		printf("Enter player name: ");
		scanf("%s", ptr->name);
		printf("Enter player age: ");
		scanf("%d", &ptr->age);
		printf("Enter player club: ");
		scanf("%s", ptr->club);
	}
	else
	//else statement used to print error message if a corresponding player code does not exist
		printf("Player does not exist.\n");
}

//This method is used to display the player list if the user selects this option
void printPlayer()
{
	struct Player *ptr;
	printf("%-25s %-25s %-25s %-25s\n", "Player Code", "Player Name", "Player Age", "Player Club");
	//Print statement used to print the headers
	for (ptr = worldcup; ptr != NULL; ptr = ptr->next)
	//for loop created to loop through the list of players and print each player's details
		printf("%-25d %-25s %-25d %-25s\n", ptr-> code, ptr->name, ptr->age, ptr->club);
}

//This method is used to delete a player from the list if the user selects this option
void deletePlayer()
{
	struct Player *temp;
	int code;
	struct Player *ptr;
	printf("Enter Player code: ");
	//Print statement used to prompt the user to enter the player code
	scanf("%d", &code);
	ptr = findPlayer(code);
	if (ptr != NULL) {
	//if statement used to check if a corresponding player code exists and update the information of the player
		free(ptr);
		//free() function used to free up allocated memory of pointer node
	}
	else
	//else statement used to print error message if a corresponding player code does not exist
		printf("Player does not exist. \n");
}
