#ifndef __STATUS_H_
#define __STATUS_H_
#define NUM_OF_LAST 10
#include "date.h"
#include <stdio.h>
#include <time.h>
#include <ctime>
#include "commands.h"
#include <string>

class Status
{
public:
	enum sType { TEXT, VIDEO, IMAGE, STVIDEO, STIMAGE};

protected:
	const time_t timeCreate;
	const sType statusType;
	//char *data;
	string data;
public:
	Status(string data, int statusType);                                     //constructor

   /*Others*/
	static Status* addStatus(string input,int type);
	static Status** mergeTen(Status**sts, Status**help);

	/*Print functions*/
	static void printArrStatus(Status**sts);
	virtual void printStatus()const;

	/*Operators*/
	bool operator==(const  Status&  other) const;
	bool operator!=(const  Status&  other) const;
};

/*===Stvideo class===*/
class Stvideo : public Status
{
public:
	Stvideo(string data, int statusType);                                     //constructor																//destructor
	virtual void printStatus()const;
};


/*===Stimage class===*/
class Stimage : public Status
{
public:
	Stimage(string data, int statusType);                                     //constructor																//destructor
	virtual void printStatus()const;
};

#endif // !StatusTable.h
