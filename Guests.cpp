#include "Guests.h"
#include "Bookings.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
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
	int found = 0;
	this->ReadConsole();
	cout << "--- ID --- imie --- nazwisko --- do zaplaty ---" << endl;
	for (unsigned int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i].name == this->temp.name && this->list[i].secName == this->temp.secName)
		{
			found++;
			cout << i << ". " << this->list[i] << endl;
		}
	}
	return 0;
}

void Guests::Remove()
{
	extern Bookings* bookings;
	int id = bookings->GetGuestID();
	this->list[id].bill -= bookings->GetPrice();
}

void Guests::ReadFile()
{
	cout << "Wczytywanie bazy gosci... ";
	fstream file;
	file.open("Data files/guests.txt", ios::in);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
	while (!file.eof() && file >> this->temp.name && file >> this->temp.secName && file >> this->temp.bill)
	{
		this->list.push_back(this->temp);
	}
	file.close();
	cout << "OK" << endl;
}

void Guests::WriteFile()
{
	cout << "Zapisywanie bazy gosci... ";
	fstream file;
	file.open("Data files/guests.txt", ios::out);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
	for (auto i : this->list)
	{
		file << i.name << " ";
		file << i.secName << " ";
		file << i.bill << endl;
	}
	file.close();
	cout << "OK" << endl;
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

		cout << "--- Wyszukiwanie klienta---" << endl << endl;
		this->Find();
		break;

	case 2:

		cout << "--- Lista wszystkich klientow---" << endl << endl;
		this->PrintAll();
		break;

	case 3:
		
		cout << "--- Pobieranie oplaty---" << endl << endl;
		this->Pay();
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

void Guests::Pay()
{
	int id;
	double v;
	cout << "Podaj ID klienta: ";
	id = GetValue(0, this->list.size() - 1);
	cout << "Calkowita naleznosc: ";
	cout << this->list[id].bill << " zl" << endl;
	cout << "Kwota pobrana: ";
	while (true)
	{
		v = GetValue(100000.00);
		if (v > this->list[id].bill)
			cout << "Zbyt duza kwota. Ponow wybor: ";
		else
			break;
	}
	this->list[id].bill -= v;
	cout << "Po zaplacie: ";
	cout << this->list[id].bill << " zl" << endl;
}