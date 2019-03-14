#include "Duration.h"


bool operator==(Duration &a, Duration &b)
{
	if (a.getTotalSec() == b.getTotalSec())
		return true;
	else
		return false;
}

bool operator<=(Duration &a, Duration &b)
{
	if (a.getTotalSec() < b.getTotalSec()) 
		return true;
	else if (a.getTotalSec() == b.getTotalSec()) 
		return true;
	else
		return false;
}

bool operator>=(Duration &a, Duration &b)
{
	if (a.getTotalSec() > b.getTotalSec()) 
		return true;
	else if (a.getTotalSec() > b.getTotalSec()) 
		return true;
	else
		return false;
}

int operator+(Duration &a, Duration &b)
{
	return a.getTotalSec() + b.getTotalSec();
}

int operator-(Duration &a, Duration &b)
{
	return a.getTotalSec() - b.getTotalSec();
}

ostream& operator<<(ostream& os, Duration &a)
{
	os << a.getHours() << ":" << a.getMinutes() << ":" << a.getSeconds();
	return os;
}
//Not sure how to overload this one.
//istream& operator>> (istream& is, Duration &a)
//{
//	
//}