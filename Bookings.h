#pragma once
#include "Database.h"
#include "Term.h"
#include <iostream>
#include <vector>
using namespace std;

struct Booking
{
	int room_ID; //ID pokoju = nr indeksu w wektorze pokoi = nr na drzwiach
	int guest_ID; //ID klienta = nr indeksu w wektorze gosci
	Term term; //termin rezerwacji

	friend ostream& operator<< (ostream&, const Booking); //przeciazenie wyjscia
	Booking(int = 0, int = -1); //konstruktor
	~Booking(); //destruktor
};

class Bookings :
	public Database
{
	vector <Booking> list;
	Booking temp;

public:
	
	virtual void ReadConsole();
	virtual void PrintAll();
	virtual int Find();
	virtual void Remove();
	virtual void ReadFile();
	virtual void WriteFile();
	virtual void Driver();

	//gettery
	double GetPrice();
};