#ifndef WORLDCUP_PLAYER_H
#define WORLDCUP_PLAYER_H
//guard commands used to protect body of header file

//Function and macro definitions outlined with corresponding variables to allow use in different files
int read_line2(char str[], int n);

struct Player;

struct Player *findPlayer(int code);

void insertPlayer();

void searchPlayer();

void updatePlayer();

void printPlayer();

void deletePlayer();
#endif
