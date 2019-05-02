#ifndef __COMMANDS_H_
#define __COMMANDS_H_

#include <string>

enum Color
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGREY = 7,
	DARKGREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};


void printTheMenu();
void printAll();
void addFriendToFriend(string name, string name2);
void addMemberToPage(string name, string page);
void setTextColor(Color colorToSet);
bool ifDateIsValid(int dd, int mm, int yy);

void FacebookActions();
#endif