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
	friend ostream& operator<< (ostream&, const Guest); //przeciazenie wyjscia
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
	virtual void Remove();
	virtual void ReadFile();
	virtual void WriteFile();
	virtual void Driver();

	//gettery
	string GetName(int);
	string GetSecName(int);
	
	//inne pomocnicze
	int Add(); //wyszukuje goscia w wektorze i dopisuje rachunek
};