#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//included needed header file required to use functions from different files
#include "worldcup_team.h"
//#define used to set maximum character length of team name to 25 characters
#define NAME_LEN 25

//Read line function created and used when entering team name to get rid of extra characters
int read_line1(char str[], int n)
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

//This structure outlines the Teams and the needed details for each portion of the Team information
struct Team
{
	int code;
	char name[NAME_LEN+1];
	char seeding[3];
	char kit[3];
	struct Team *next;
};

//Head structure node
struct Team *worldcup2 = NULL;

//This structure is used to find the corresponding team with the team code and perform different functions
struct Team *findTeam(int code)
{
	struct Team *ptr;
	for (ptr = worldcup2; ptr != NULL && code > ptr->code; ptr = ptr->next);
	if (ptr != NULL && code == ptr->code)
		return ptr;
	return NULL;
}

//This method is created to input details of each team by taking a reference of the Team structure then taking data from the user into the structure
void insertTeam()
{
	struct Team *currentNode, *previousNode, *newNode;

	newNode = malloc(sizeof(struct Team));

	if (newNode == NULL) {
	//if statement created to check if the database is full and return an error message if it is
		printf("Database is full, no new teams can be added.\n");
		return;
	}

	printf("Enter team code: ");
	//Prompt for the user to enter the team code
	scanf("%d", &newNode->code);
	for (currentNode = worldcup2, previousNode = NULL; currentNode != NULL && newNode->code > currentNode->code; previousNode = currentNode, currentNode = currentNode->next);
	//for loop used to check if the code already exists in the database
	if (currentNode != NULL && newNode ->code == currentNode->code){
		printf("Team already exists. \n");
		//Prints an error message and frees up node allocated memory while returning to initial operation code prompt
		free(newNode);
		return;
	}
	printf("Enter team name: ");
	//Prompt for user to enter the team name
	read_line1(newNode->name, NAME_LEN);
	//Read line function called when entering the name value to properly interpret characters entered
	printf("Enter group seeding: ");
	//Prompt for user to enter the group seeding value
	scanf("%s", newNode->seeding);
	printf("Enter kit colour: ");
	//Prompt the user to enter the team kit colour
	scanf("%s", newNode->kit);
	newNode->next = currentNode;

	if (previousNode == NULL)
	//if statement used to set the worldcup2 node to the newNode value if the previousNode is equal to NULL

		worldcup2 = newNode;
	else
		previousNode->next = newNode;
}

//This method is used to search for a team in the database if selected by the user
void searchTeam()
{
	int code;
	struct Team *ptr;
	printf("Enter team code: ");
	scanf("%d", &code);
	ptr = findTeam(code);
	if (ptr != NULL) {
		printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
        printf("%-25d %-25s %-25s %-25s\n", ptr-> code, ptr->name, ptr->seeding, ptr->kit);
	}
	else
		printf("Team does not exist. \n");
}

//This method is used to update a team's details in the database if the user selects this option
void updateTeam()
{
	int code;
	struct Team *ptr;
	printf("Enter team code: ");
	//Print statement used to prompt the user to enter the team code
	scanf("%d", &code);
	ptr = findTeam(code);
	if (ptr != NULL)
	{
	//if statement used to check if a corresponding team code exists and update the information of the team
		printf("Enter team name: ");
		scanf("%s", ptr->seeding);
		printf("Enter group seeding: ");
		scanf("%s", ptr->seeding);
		printf("Enter kit colour: ");
		scanf("%s", ptr->kit);
	}
	else
	//else statement used to print error message if a corresponding player code does not exist
		printf("Team does not exist.\n");
}

//This method is used to display the team list if the user selects this option
void printTeam()
{
	struct Team *ptr;
	printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
	//Print statement used to print the headers
	for (ptr = worldcup2; ptr != NULL; ptr = ptr->next)
		//for loop created to iterate through the list of players and print each team's details
		printf("%-25d %-25s %-25s %-25s\n", ptr->code, ptr->name, ptr->seeding, ptr->kit);
}

//This method is used to delete a player from the list if the user selects this option
void deleteTeam()
{
	struct Team *temp;
	int code;
	struct Team *ptr;
	printf("Enter team code: ");
	//Print statement used to prompt the user to enter the player code
	scanf("%d", &code);
	ptr = findTeam(code);
	if (ptr != NULL) {
	//if statement used to check if a corresponding player code exists and update the information of the player
		free(ptr);
		//free() function used to free up allocated memory of pointer node
	}
	else
	//else statement used to print error message if a corresponding player code does not exist
		printf("Team does not exist. \n");
}

