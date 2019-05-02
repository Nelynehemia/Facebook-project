#ifndef __OBJECT_H_
#define __OBJECT_H_
#include "status.h"
#include <vector>
#define FANPAGE 0
#define MEMBER 1

class member;

class object
{
protected:
	string name;
	bool type; //(0 for fanpage 1 for member)

	//friend arr
	vector<object*> arrFriends;

	//status arr
	vector<Status*> arrStatus;

	//total Arr
	static vector<object*> totalArr;

	object(string name, bool type);                          //constructor
	virtual ~object();                                      //destructor

public:
	/*other*/
	static object * findObject(string name, bool type);
	Status* statusadress();

	/*Add functions*/
	static void addObject(object * new_page);
	void addStatusToObject(Status *statusToAdd);
	void addFriendToObject(object * mbr);

	/*Print functions*/
	static void printTotalArr();
	void printArrStatus()                             const;
	void printArrFriend()                             const;
	void printName()                                  const;

	/*delete functions*/
	static void delTotalArr();

	/*operators*/
	object & object::operator+=(object & other);
	bool operator<(const  object&  other) const;
};


#endif // object.h