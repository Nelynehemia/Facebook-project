#ifndef __MEMBER_H_
#define __MEMBER_H_

#include "FanPage.h"
#include "date.h"
#include "status.h"
#include "object.h"

class fanPage;

class member : public object
{
private:
	const date dateOfBirth;

	//FanPages arr
	vector<fanPage*>arrFanPage;

public:
	member(string name, date dBirth) :object(name, 1), dateOfBirth(dBirth) {}//constructor

	 /*add functions*/
	void AddFanPageToFriend(fanPage *FanpageToAdd);

	/*other*/
	Status** lastTen();
	void tenOfUsers(Status ** help);
	bool isFriendOf(member *mbr);

	/*print functions*/
	void printArrFanPage()                                const;
	virtual void print()                                  const;

};


#endif // !_member.h
