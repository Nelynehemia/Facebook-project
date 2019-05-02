#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "status.h"



/*Constractors*/
Status::Status(string data, int statusType) :timeCreate(time(nullptr)), statusType((sType)statusType)
{
	if (!data.empty())
	{
		this->data = data;
	}
}


Status* Status::addStatus(string input, int statusType)
{
	switch (statusType)
	{
	case 0:{
		return new Status(input, statusType);
		break;
	}
	case 1: {
		return new Stvideo(input, statusType);
		break;
	}
	case 2: {
		return new Stimage(input, statusType);
		break;
	}
	case 3: {
		return new Stvideo(input, statusType);
		break;
	}
	case 4: {
		return new Stimage(input, statusType);
		break;
	}

	default:
		break;
	}
	return nullptr;
}
Status** Status::mergeTen(Status**sts, Status**help)
{
	Status ** res = new Status*[NUM_OF_LAST];
	for (int i = 0; i < NUM_OF_LAST; i++)
		res[i] = nullptr;

	int s1 = 0, s2 = 0, i = 0;
	while (i < NUM_OF_LAST && (sts[s1] != nullptr || help[s2] != nullptr))
	{
		if (sts[s1] != nullptr && help[s2] != nullptr)
		{
			if (sts[s1]->timeCreate > help[s2]->timeCreate)
				res[i++] = sts[s1++];
			else
				res[i++] = help[s2++];
		}
		else if (sts[s1] != nullptr)
			res[i++] = sts[s1++];
		else
			res[i++] = help[s2++];
	}
	delete[]sts;
	return res;
}

/*Print functions*/
void Status::printStatus()const
{
	setTextColor(WHITE);
	char* dt = ctime(&timeCreate);
	cout << dt;

	if (!data.empty())
		cout << "TEXT: " << data <<"." << endl;
}
void Status::printArrStatus(Status**sts)
{
	if (sts == nullptr || *sts == nullptr)
		cout << "There are no statuses" << endl;
	else
	{
		int i = 0;
		while (sts[i] != nullptr && i < NUM_OF_LAST)
		{
			cout << i + 1 << ". ";
			sts[i++]->printStatus();
		}
	}
	delete[]sts;
}

/*Operators*/
bool Status::operator==(const  Status&  other) const
{
	bool flag = this->statusType == other.statusType;
	if (!(this->data.empty()) && (!other.data.empty()))
		return (flag && ((this->data.compare( other.data)) == 0));
	else
		return false;
}
bool Status::operator!=(const  Status&  other) const
{
	return !(*this == other);
}

/*===Stvideo class===*/

/*Constractors*/
Stvideo::Stvideo(string data, int statusType) : Status(data, statusType) {}

void Stvideo::printStatus()const
{

	Status::printStatus();
	setTextColor(LIGHTBLUE);
	cout << "VIDEO: \n";
	setTextColor(WHITE);
}


/*===Stimage class===*/

/*Constractors*/
Stimage::Stimage(string data, int statusType) : Status(data, statusType) {}


void Stimage::printStatus()const
{
	Status::printStatus();
	setTextColor(LIGHTRED);
	cout << "IMAGE: \n";
	setTextColor(WHITE);
}

