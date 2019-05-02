#include <windows.h>
#define WINDOWS
#include "object.h"
#include "member.h"
#include "commands.h"


void FacebookActions()
{
	char ch, type;
	string input;
	string input2;
	int dd, mm, yy, statusType;
	cin >> ch;
	object* ptr=nullptr;

	/*The loop*/
	while (ch != '9')
	{
		//clear inputs
		input.clear();
		input2.clear();

		switch (ch) {
		case '1': {
			cout << "Enter name: \n";
			cin.ignore(1);
			getline(cin,input);

			while (member::findObject(input, MEMBER))
			{
				cout << "The name is in the system, Please choose another: " << endl;
				getline(cin, input);
			}
			cout << "Enter date of birth: (in format: dd, mm, yyyy ) \n";
			cin >> dd >> mm >> yy;
			cin.clear();
			while (ifDateIsValid(dd, mm, yy))
			{
				cin >> dd >> mm >> yy;
				cin.ignore();
				cin.clear();
			}
			member * new_member = new member(input, date(dd, mm, yy));
			member::addObject(new_member);
			break;
		}
		case '2': {
			cout << "Please enter FanPage name:"; // then prints "2"
			cin.ignore(1);
			getline(cin, input);
			while (fanPage::findObject(input, FANPAGE))
			{
				cout << "The name is in the system, Please choose another: " << endl;
				cin.ignore(1);
				getline(cin, input);
			}
			fanPage * page_to_add = new fanPage(input);
			fanPage::addObject(page_to_add);
			break;
		}
		case '3': {
			cout << "Add status: for friend type: 'f' for page type 'p': " << endl;
			cin >> type;
			cout << "Enter Name of Friend/Page: " << endl;
			cin.ignore(1);
			getline(cin, input);
			if (type == 'f')
				ptr = member::findObject(input, MEMBER);
			else if (type == 'p')
				ptr = fanPage::findObject(input, FANPAGE);

			if (ptr == nullptr)
			{
				cout << "ERROR: couldn't find this Object \n";
				break;
			}
			
			cout << "Please enter type of status ( 0 for text, 1 for video, 2 for image, 3 for text&video, 4 for text&image ) " << endl;
			cin >> statusType;
			
			if (statusType != 1 && statusType != 2)
			{
				cout << "Enter status data: " << endl;
				cin.ignore(1);
				getline(cin, input2);
				
			}
			else if (statusType != 0 && statusType != 1 && statusType != 2 && statusType != 3 && statusType != 4)
			{
				cout << "Incorrect typing !" << endl;
				break;
			}
			Status* newStatus = Status::addStatus(input2, statusType);
			ptr->addStatusToObject(newStatus);
			break;
		}
		case '4': {
			cout << "Print status: for friend type: 'f' for page type 'p': " << endl;
			cin >> type;
			if (type != 'f' && type != 'p')
			{
				cout << "Incorrect typing \n";
				break;
			}
			cout << "Enter Name of Friend/Page: " << endl;
			cin.ignore(1);
			getline(cin, input);
			if (type == 'f')
				ptr = member::findObject(input, MEMBER);
			else if (type == 'p')
				ptr = fanPage::findObject(input, FANPAGE);

			if (ptr == nullptr)
				cout << "ERROR: couldn't find this Object";
			else
				ptr->printArrStatus();

			break;
		}
		case '5': {
			cout << "Please enter the First member name:\n";
			cin.ignore(1);
			getline(cin, input);
			cout << "Please enter the Second Member name:\n";
			getline(cin, input2);
			addFriendToFriend(input2, input);
			break;
		}
		case '6': {
			cout << "Please enter the FanPage name:\n";
			cin.ignore(1);
			getline(cin, input);
			cout << "Please enter the Member name:\n";
			getline(cin, input2);
			addMemberToPage(input2, input);
			break;
		}
		case '7': {
			object::printTotalArr();
			break;
		}
		case '8': {
			cout << "Print friend of: for friend type: 'f' for page type 'p': " << endl;
			cin >> type;
			if (type != 'f' && type != 'p')
			{
				cout << "Incorrect typing \n";
				break;
			}
			cout << "Enter Name of Friend/Page: " << endl;
			cin.ignore(1);
			getline(cin, input);
			if (type == 'f')
				ptr = member::findObject(input, MEMBER);
			else if (type == 'p')
				ptr = fanPage::findObject(input, FANPAGE);

			if (ptr == nullptr)
				cout << "ERROR: couldn't find this Object";
			else
			{
				cout << "The list of friends: \n";
				ptr->printArrFriend();
			}
			break;
		}
		case 'd': {
			cout << "Please enter the First member name:\n";
			cin.ignore(1);
			getline(cin, input);
			cout << "Please enter the Second Member name:\n";
			getline(cin, input2);
			object* ptr = member::findObject(input, MEMBER);
			object* ptr2 = member::findObject(input2, MEMBER);
			
			if (ptr == nullptr || ptr2 == nullptr)
			{
				cout << "ERROR: one of the friends does not exist";
				break;
			}
			Status *sts1 = ptr->statusadress();
			Status *sts2 = ptr2->statusadress();
			if (sts1 == nullptr || sts2 == nullptr)
			{ 
				cout << "ERROR: one of the users have no status";
				break;
			}
			if (*sts1 == *sts2)
				cout << "Equal!";
			else
				cout << "Not Equal";
			break;
		}
		case 'p': {
			printAll();
			break;
		}
		case 't': {
			cout << "Enter Name of Friend: " << endl;
			cin.ignore(1);
			getline(cin, input);
			member* obj = (member*)member::findObject(input, MEMBER);
			if (obj == nullptr)
				cout << "ERROR: couldn't find this member";
			else
				Status::printArrStatus(obj->lastTen());
			break;
		}
		}

		printTheMenu();
		cin >> ch;
	}

	/*Delete*/
	object::delTotalArr();
}

void printAll()
{
	object::printTotalArr();
}
void printTheMenu()//This function print the menu
{
	cout << "\nWellcome to facebook\n";
	cout << "List Of Aviable commands:\n";
	cout << "1. Add New Friend\n"; //
	cout << "2. Add New Fanpage\n"; //
	cout << "3. Add Status to Friend or Page\n";
	cout << "4. Prints all statuses Of a friend / fan page\n";
	cout << "5. Add Friend To Friend\n";//
	cout << "6. Add member to fanpage\n"; //
	cout << "7. Print All Member's and Page's\n";//
	cout << "8. Print list of friends of page/members\n";
	cout << "t. Last 10 status from member friend's\n";
	cout << "d. Check if the last status of 2 friends are equal\n";
	cout << "9 to exit\n\n";
	cout << ">>";
}

void addMemberToPage(string name,string page) //6. command
{
	member* pMbr = (member*)member::findObject(name, MEMBER);
	fanPage* pFage = (fanPage*)fanPage::findObject(page, FANPAGE);

	if (pMbr && pFage)
		*pMbr += *pFage;
	else
		cout << "ERROR" << endl;
}
void addFriendToFriend(string name,string name2) //5. command
{
	if ((name.compare(name2)) == 0)
		cout << "ERROR: a friend cannot be friend with himself." << endl;
	else
	{
		member* mbr1 = (member*)member::findObject(name, MEMBER);
		member* mbr2 = (member*)member::findObject(name2, MEMBER);
		if (mbr1 == nullptr || mbr2 == nullptr)
			cout << "ERROR: One of the friends not exist." << endl;
		else if (mbr1->isFriendOf(mbr2) == true)
			cout << "ERROR: Already friends of each other." << endl;
		else {
			*mbr1 += *mbr2;
			}
	}
}
void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}
bool ifDateIsValid(int dd, int mm, int yy)
{
	if (!(dd > 0 && dd < 32) || !(mm > 0 && mm < 13) || !(yy > 1700 && yy < 2019))
	{
		cout << "Incorrect input \n";
		return true;
	}
	return false;
}

