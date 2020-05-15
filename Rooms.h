#pragma once
#include "Database.h"
#include "Term.h"
#include <iostream>
#include <vector>
using namespace std;

struct Room
{
	string name; //nazwa pokoju
	double price; //cena za osobe za noc
	int max_person; //maksymalna ilosc osób w apartamencie
	vector<string> facilities; //dodatkowe informacje o apartamencie
	vector<Term> terms; //terminy, w ktorych pokoj jest zarezerwowany

	void GetFacilities(string); //wpisuje udogodnienia do wektora
	friend ostream& operator<< (ostream&, const Room); //przeciazenie wyjscia
	Room(string = "brak", double = 0.0, int = 0); //konstruktor
	~Room(); //destruktor
};

class Rooms :
	public Database
{
	vector <Room> list;

public:

	virtual void ReadConsole();
	virtual void PrintAll();
	virtual int Find();
};