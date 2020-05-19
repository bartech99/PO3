#include "Term.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

void Date::operator=(Date a)
{
	day = a.day;
	month = a.month;
	year = a.year;
}

ostream& operator<<(ostream& s, const Date a)
{
	if (a.day < 10)
		s << "0";
	s << a.day << "/";

	if (a.month < 10)
		s << "0";
	s << a.month << "/" << a.year;

	return s;
}

istream& operator>>(istream& s, Date& a)
{
	static string line;
	cin >> a.day;
	getline(s, line, '/') >> a.month;
	getline(s, line, '/') >> a.year;
	return s;
}

Date::Date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

Date::~Date()
{
}

void Term::operator=(Term a)
{
	from = a.from;
	to = a.to;
}

ostream& operator<<(ostream& s, const Term a)
{
	s << a.from << "-" << a.to;
	return s;
}

istream& operator>>(istream& s, Term& a)
{
	static string line;
	cin >> a.from;
	getline(s, line, '-') >> a.to;
	return s;
}

string Term::TermToString()
{
	stringstream ss;
	ss << *this;
	return ss.str();
}

Term Term::StringToTerm(string line)
{
	Date date;
	string temp;
	int pos1 = 0;
	int pos2 = 0;

	pos2 = line.find('/') + 1;
	temp += line.substr(0, pos2);
	pos1 = pos2;
	date.day = atoi(temp.c_str());

	pos2 = line.find('/', pos1);
	temp = line.substr(pos1, pos2 - pos1);
	pos1 = pos2 + 1;
	date.month = atoi(temp.c_str());

	pos2 = line.find('-', pos1);
	temp = line.substr(pos1, pos2 - pos1);
	pos1 = pos2 + 1;
	date.year = atoi(temp.c_str());

	this->from = date;

	pos2 = line.find('/', pos1);
	temp = line.substr(pos1, pos2 - pos1);
	pos1 = pos2 + 1;
	date.day = atoi(temp.c_str());

	pos2 = line.find('/', pos1);
	temp = line.substr(pos1, pos2 - pos1);
	pos1 = pos2 + 1;
	date.month = atoi(temp.c_str());

	pos2 = line.length();
	temp = line.substr(pos1, pos2 - pos1);
	date.year = atoi(temp.c_str());

	this->to = date;

	return *this;
}

int Term::DaysBetween()
{
	Date from = this->from;
	Date to = this->to;
	struct tm a = { 0, 0, 0, from.day, from.month, from.year - 1900 };
	struct tm b = { 0, 0, 0, to.day, to.month, to.year - 1900 };
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	if (x != (time_t)(-1) && y != (time_t)(-1))
		return int(difftime(y, x) / int(60 * 60 * 24));
	return 0;
}