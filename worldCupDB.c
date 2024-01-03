#include <stdio.h>
#include <stdlib.h>
#include "worldcupDB.h"
#include "worldcup_team.h"
#include "worldcup_player.h"
//included needed header files required to use functions from different files

int main()
{
	printf("****************************************\n");
	printf("*           2211 World Cup              *\n");
    printf("****************************************\n\n");
	//Prints the World Cup Header

	char choice;

	while(1)
	{
		printf("Enter operation code: ");
		fflush(stdin);
		scanf("%c", &choice);
		switch(choice)
		//Perform operation based on user code
		{
			case 'h':
				printf("In order to use this program, select either teams or players to continue");
				break;

			case 'q':

				break;

			case 't':
				while (1)
				{
					choice = getOperationCode();
					switch(choice)
					{
						case 'i':
							insertTeam();
					    	break;
					     case 's':
					    	 searchTeam();
					         break;
					     case 'u':
					         updateTeam();
					         break;
					     case 'p':
					         printTeam();
					         break;
					     case 'd':
					         deleteTeam();
					     case 'q':
					    	 exit(0);
					         break;
					     default:
					    	 printf("Invalid choice, please try again\n");
					         break;
					}

					printf("\n");
				}
				break;

			case 'p':
				while (1)
				{
					choice = getOperationCode();
					switch(choice)
					{
						case 'i':
							insertPlayer();
							break;
						case 's':
							searchPlayer();
							break;
						case 'u':
							updatePlayer();
							break;
						case 'p':
							printPlayer();
							break;
						case 'd':
						    deletePlayer();
						    break;
						case 'q':
							exit(0);
							break;
						default:
							printf("Invalid choice, please try again\n");
							break;
					}

					printf("\n");

				}
				break;

			default:
				printf("Invalid choice, please try again\n");
		}
	}
	return 0;
}
