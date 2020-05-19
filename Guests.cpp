#include "Guests.h"
#include "Bookings.h"
#include "Menu.h"
#include <iostream>
using namespace std;

bool Guest::operator==(const Guest arg)
{
	if (arg.name == this->name && arg.secName == this->secName)
		return true;
	else
		return false;
}

ostream& operator<< (ostream& s, const Guest guest)
{
	s << guest.name << " " << guest.secName << ": " << guest.bill << "zl";
	return s;
}

Guest::Guest(string n, string sc, double b)
{
	this->name = n;
	this->secName = sc;
	this->bill = b;
}

Guest::~Guest()
{
}

void Guests::ReadConsole()
{
	cout << "Imie klienta: ";
	cin >> this->temp.name;
	cout << "Nazwisko klienta: ";
	cin >> this->temp.secName;
}

void Guests::PrintAll()
{
	cout << "--- Imie --- nazwisko --- do zaplaty ---" << endl;
	for (auto i : this->list)
		cout << i << endl;
}

int Guests::Find()
{
	return 0;
}

void Guests::Remove()
{
}

void Guests::ReadFile()
{
}

void Guests::WriteFile()
{
}

void Guests::Driver()
{
	Menu* menu = new Menu();
	menu->ListGuest();
	switch (menu->GetChoise(3))
	{
	case 0:

		return;

	case 1:

		break;

	case 2:

		this->PrintAll();
		break;

	case 3:

		break;
	}
	PressAnyKey();
}

string Guests::GetName(int x)
{
	return this->list[x].name;
}

string Guests::GetSecName(int x)
{
	return this->list[x].secName;
}

int Guests::Add()
{
	extern Bookings* bookings;
	this->ReadConsole();
	for(unsigned int i = 0; i < this->list.size(); i++)
	{
		if (this->temp.name == this->list[i].name && this->temp.secName == this->list[i].secName)
		{
			this->list[i].bill += bookings->GetPrice();
			return i;
		}
	}
	this->temp.bill = bookings->GetPrice();
	this->list.push_back(temp);
	return this->list.size() - 1;
}