#pragma once
#include <iostream>
using namespace std;

/*
 * Klasa definiuje typ Date, przechowujacy date.
 */

class Date
{
	int day;
	int month;
	int year;

public:

	friend class Term;

	void operator= (Date);
	bool operator< (Date);
	bool operator> (Date);
	bool operator== (Date);
	friend ostream& operator<<(ostream&, const Date);
	friend istream& operator>>(istream&, Date&);

	Date(int a = 1, int b = 1, int c = 2000);
};

/*
 * Klasa definiuje typ Term, przechowujacy termin.
 * Sklada sie z dwoch obiektow typu Date.
 */


class Term
{
	Date from;
	Date to;

public:

	void operator= (Term);
	friend ostream& operator<< (ostream&, const Term);
	friend istream& operator>> (istream&, Term&);
	bool operator< (Term);
	bool operator> (Term);
	bool operator== (Term);

	bool Begins(); //czy ten termin zaczyna sie dzisiaj
	bool Ends(); //czy ten termin konczy sie dzisiaj
	string TermToString();
	Term StringToTerm(string);
	int DaysBetween();
};