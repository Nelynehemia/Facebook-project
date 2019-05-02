#define _CRT_SECURE_NO_WARNINGS


using namespace std;

#include "object.h"
#include "member.h"

/*Static varibles*/
vector<object*> object::totalArr;

object::object(string name, bool type)
//constructor
{
	this->name = name;
	this->type = type;
	}
object::~object()
{
	for (size_t i = 0; i < arrStatus.size(); i++)
		delete arrStatus[i];
}


/*Add functions*/
void object::addObject(object* new_page)
//This function add new FanPage
{
	totalArr.push_back(new_page);
}
void object::addStatusToObject(Status *statusToAdd)
//This function add status
{
	arrStatus.push_back(statusToAdd);
}
void object::addFriendToObject(object * mbr)
{
	arrFriends.push_back(mbr);
}

/*Print functions*/
void object::printArrStatus()const
{
	if (arrStatus.size() == 0)
	{
		cout << "There are no statuses" << endl;
		return;
	}
	for (size_t i = 0; i < arrStatus.size(); i++)
		arrStatus[i]->printStatus();
}
void object::printArrFriend()const
{
	if (arrFriends.size() == 0)
		cout << "I'm sorry, there is no friends :("<<endl;
	else
	{
		cout << "The list of friends: \n";
		for (size_t i = 0; i < arrFriends.size(); i++)
		{
			if (arrFriends[i])
				arrFriends[i]->printName();
		}

	}
}

//PrintFriendsOfPage
void object::printTotalArr()
{
	
	int k = 0;
	cout << "List of members:\n";
	for (size_t i = 0; i < totalArr.size(); i++)
	{
		if (dynamic_cast<member*>(totalArr[i]))
		{
			cout << k + 1 << ". ";
			((member *)totalArr[i])->print();
			k++;
			cout << endl;
		}
	}
	cout << "-------" << endl;
	k = 0;
	cout << "List of fanPage:\n";
	for (size_t i = 0; i < totalArr.size(); i++)
	{
		if (dynamic_cast<fanPage*>(totalArr[i]))
		{
			cout << k + 1 << ". ";
			((fanPage*)totalArr[i])->print();
			k++;
			cout << endl;
		}
	}
	cout << "-------" << endl;

}
void object::printName()const
{
	cout << name << " ";
}

/*Others*/
object * object::findObject(string name, bool type)
{
	for (size_t i = 0; i < totalArr.size(); i++)
		if ((totalArr[i]->type == type) && ((totalArr[i]->name.compare(name)) == 0))
			return totalArr[i];
	return nullptr;
}
Status* object::statusadress()
{
	if (arrStatus.size() == 0)
		return nullptr;
	return arrStatus[arrStatus.size() - 1];
}

/*delete functions*/
void object::delTotalArr()
{
	for (size_t i = 0; i < totalArr.size(); i++)
		delete totalArr[i];
}

/*Operators functions*/
object & object::operator+=( object & other)
{
	this->addFriendToObject(&other);
	other.addFriendToObject(this);
	return *this;
}
bool object::operator<(const  object&  other) const
{
	return (this->arrFriends.size() < other.arrFriends.size());
}


