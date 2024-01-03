#ifndef WORLDCUP_TEAM_H
#define WORLDCUP_TEAM_H
//guard commands used to protect body of header file

//Function and macro definitions outlined with corresponding variables to allow use in different files
int read_line1(char str[], int n);

struct Team;

struct Team *findTeam(int code);

void insertTeam();

void searchTeam();

void updateTeam();

void printTeam();

void deleteTeam();
#endif
