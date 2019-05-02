
#include "fanpage.h"


fanPage::fanPage(string name) : object(name, FANPAGE) {}

void fanPage::print()const
{
	cout << name << endl;
	cout << "The people who like it:\n";
	printArrFriend();
}
