#define _CRT_SECURE_NO_WARNINGS 


#include "member.h"
#include <string.h>
#include <stdio.h>
#include <iostream>


/*Add functions*/
void member::AddFanPageToFriend(fanPage *FanpageToAdd)
{
	arrFanPage.push_back(FanpageToAdd);
}

/*Print functions*/
void member::print()const
{
	cout << "name: " << name << " | date Of Birth: ";
	dateOfBirth.print();
}
void member::printArrFanPage()const
{
	for (size_t i = 0; i < arrFanPage.size(); i++)
		arrFanPage[i]->print();
}

/*Others*/
Status** member::lastTen()
{
	Status** res = new Status*[NUM_OF_LAST]; //we need to zero res
	Status* help[NUM_OF_LAST];
	if (arrFriends.size() == 0)
		return nullptr;

	//first member
	((member*)arrFriends[0])->tenOfUsers(res);

	//run on all member
	for (int k = 1; k < arrFriends.size(); k++)
	{
		((member*)arrFriends[k])->tenOfUsers(help);
		res = Status::mergeTen(res, help);
	}
	return res;
}
void member::tenOfUsers(Status ** help)
{
	//zero the array
	for (int i = 0; i < NUM_OF_LAST; i++)
		help[i] = nullptr;
	int k = 0;
	if (arrStatus.size() == 0)
		return;
	if (arrStatus.size() < NUM_OF_LAST)
	{
		for (int i = arrStatus.size() - 1; i >= 0; i--)
			help[k++] = arrStatus[i];
	}
	else
	{
		for (int i = arrStatus.size() - 1; i >= arrStatus.size() - NUM_OF_LAST; i--)
			help[k++] = arrStatus[i];
	}

}
bool member::isFriendOf(member *mbr)
{
	if (arrFriends.size() == 0)
		return false;
	int i = 0;
	while (i<arrFriends.size())
	{
		if (mbr == arrFriends[i])
			return true;
	}
	return false;
}

	