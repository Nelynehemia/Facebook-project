#ifndef __DATE_H_
#define __DATE_H_

#include <iostream>
#include <string.h>
using namespace std;

class date
{
private:
	int d, m, y;
public:
	date(int dd, int mm, int yy) { d = dd, m = mm, y = yy; }         //constructor
	void print() const { cout << d << "." << m << "." << y; }        //print

};

#endif // !_date

