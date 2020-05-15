#pragma once
#include "Database.h"
#include <iostream>
#include <vector>
using namespace std;

struct Guest
{
	string name; //imie klienta
	string secName; //nazwisko klienta
	double bill; //do zaplaty

	bool operator==(const Guest);
	Guest(string = "brak", string = "brak" , double = 0.0); //konstruktor
	~Guest(); //destruktor
};

class Guests :
	public Database
{
	vector <Guest> list;
	Guest temp;

public:

	virtual void ReadConsole();
	virtual void PrintAll();
	virtual int Find();
};