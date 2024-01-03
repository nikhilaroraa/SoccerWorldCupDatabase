#include <stdio.h>
#include <string.h>

//#define used to set maximum team number to 32
#define MAX_TEAMS 32

//This structure outlines the Teams and the needed details for each portion of the team
struct Team
{
    int code;
    char name[25];
    char seeding[25];
    char kit;
};

//This method is used to print the Initial header in the program
void worldCupHeader()
{
    printf("****************************************\n");
    printf("*           2211 World Cup              *\n");
    printf("****************************************\n\n");
}

//This method is used to prompt the user for the initial operation code entry and to return the user choice selected
char getOperationCode()
{
    printf("Enter operation code: ");
    char choice;
    scanf(" %c", &choice);
    return choice;
}

//This method is used to check if the Team code is unique when inputting in new teams
int getTeamIndex(struct Team teams[], int count, int code)
{
    for(int i = 0; i < count; i++){
        if(teams[i].code == code){
            return i;
        }
    }

    return -1;
}
//This method is used to check if the team name is unique when inputting in new teams
int getTeamNameIndex(struct Team teams[], int count, char *name)
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(teams[i].name,name) == 0)
        //strcmp used to compare the two string values
        {
            return i;
        }
    }

    return -1;
}
//This method is used to check if the group seeding is unique when inputting in new teams
int getGroupSeedingIndex(struct Team teams[], int count, char *groupseeding)
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(teams[i].seeding,groupseeding) == 0)
        //strcmp used to compare the two string values
        {
            return i;
        }
    }

    return -1;
}

//This method is created to input details of each team by taking a reference of the Team structure then take data from the user into the structure
int getTeam(struct Team teams[], int count)
{
    int code;

    printf("\tEnter team code: ");
    //Prompt for the user to enter the team code
    scanf("%d", &code);
    if(code < 0 || code > 31)
    {
    //if statement to check if the number entered is within the given range
        printf("Not a valid code\n");
        return 0;
    }
    else if (getTeamIndex(teams, count, code) != -1)
    //else if statement created to check if the code exists in the database
    {
    	printf("Team already exists.\n");
    	//Prints an error message and returns to initial operation code prompt
        return 0;
    }

    teams[count].code = code;

    printf("\tEnter team name: ");
    //Prompt for the user to enter the team name
    scanf("%s", teams[count].name);
    if (getTeamNameIndex(teams, count, teams[count].name) != -1)
    //if statement created to check if the team name already exists in the database
    {
    	printf("Team name already exists.\n");
    	//Prints an error message and returns to initial operation code prompt
        return 0;
    }


    printf("\tEnter group seeding: ");
    scanf("%s", teams[count].seeding);
    if (getGroupSeedingIndex(teams, count, teams[count].seeding) != -1)
    //if statement created to check if the team name already exists in the database
    {
    	printf("Group Seeding already exists.\n");
    	//Prints an error message and returns to initial operation code prompt
    	return 0;
     }

    if(teams[count].seeding[0] < 'A' || teams[count].seeding[0] > 'H' || teams[count].seeding[1] < 49 || teams[count].seeding[1] > 52)
    //if statement created to check if the group seeding is within the range of A-H and 1-4
    {
        printf("Not a valid group seeding option.\n");
        //Prints an error message if not within the parameters and returns to initial operation code prompt
        return 0;
    }

    char kit;
    printf("\tEnter the kit color: ");
    scanf(" %c", &kit);

    if(kit != 'R' && kit != 'O' && kit != 'Y' && kit != 'G' && kit != 'B' && kit != 'I' && kit != 'V')
    //if statement created to check if the kit colour is one of the listed colours available

    {
        printf("Not a valid color option.\n");
        //Prints an error message if not within the parameters and returns to initial operation code prompt
        return 0;
    }
    teams[count].kit = kit;

    return 1;

}

//This method is used to update a team's details in the database if the user selects this option
void update(struct Team teams[], int count)
{
    int code;
    printf("\tEnter team code: ");
    //print statement used to prompt the user to enter the team code
    scanf("%d", &code);
    int index = getTeamIndex(teams, count, code);
    if (index == -1)
    //if statement used to check if there is a team with the same team code
    {
        printf("Team does not exist.\n");
        //prints an error message if there is no team with the same team code entered
    }
    else
    {
        //Enter in other details
        printf("\tEnter team name: ");
        scanf("%s", teams[index].name);

        printf("\tEnter group seeding: ");
        scanf("%s", teams[index].seeding);

        if(teams[index].seeding[0] < 'A' || teams[index].seeding[0] > 'H' || teams[index].seeding[1] < 49 || teams[index].seeding[1] > 52)
        {
            printf("Not a valid group seeding.\n");
            return;
        }

        char kit;
        printf("\tEnter the kit color: ");
        scanf(" %c", &kit);

        if(kit != 'R' && kit != 'O' && kit != 'Y' && kit != 'G' && kit != 'B' && kit != 'I' && kit != 'V')
        {
            printf("Not a valid color.\n");
            return;
        }
        teams[index].kit = kit;
    }
}
//This method is used to change the character value entered for the kit colours to String values
char* charToColour(char colour)
{
    if(colour == 'R')
    {
        return "Red";
    }
    else if(colour == 'O')
    {
        return "Orange";
    }
    else if(colour == 'Y')
    {
        return "Yellow";
    }
    else if(colour == 'G')
    {
        return "Green";
    }
    else if(colour == 'B')
    {
        return "Blue";
    }
    else if(colour == 'I')
    {
        return "Indigo";
    }
    else
    //if the value is not equal to any of the other letters then colour == 'V' in this case
    {
        return "Violet";
    }

}

//This method is used to search for a team in the database if selected by the user
void search(struct Team teams[], int count)
{
    int code;
    printf("\tEnter team code: ");
    //print statement used to prompt the user to enter the team code
    scanf("%d", &code);
    int index = getTeamIndex(teams, count, code);
    if (index == -1)
    {
        printf("Team does not exist.\n");
    }
    else
    {
        //print statement used to print the headers
        printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
        //print statement used to print the team details
        printf("%-25d %-25s %-25s %-25s\n", teams[index].code, teams[index].name, teams[index].seeding, charToColour(teams[index].kit));
    }
}

//This method is used to display the team list if the user selects this option
void print(struct Team teams[MAX_TEAMS], int count)
{
    printf("%-25s %-25s %-25s %-25s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
    //print statement used to print the headers

    for(int index = 0; index < count; index++)
    //for loop created to loop through the list of teams and print each team's details
    {
        printf("%-25d %-25s %-25s %-25s\n", teams[index].code, teams[index].name, teams[index].seeding, charToColour(teams[index].kit));
    }

}


int main()
{
    //Structure array created to represent up to 32 possible teams
    struct Team teams[MAX_TEAMS];
    int count = 0;

    //Prints the World Cup Header
    worldCupHeader();

    char choice;

    while (choice != 'q')
    {
        //Used to get the input choice from the user
        choice = getOperationCode();

        // Perform operation based on user code
        switch(choice)
        {
            case 'i':
                if (getTeam(teams, count))
                {
                    count++;
                }
                break;
            case 's':
                search(teams, count);
                break;
            case 'u':
                update(teams, count);
                break;
            case 'p':
                print(teams, count);
                break;
            case 'q':

                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
