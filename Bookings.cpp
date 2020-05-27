#include "Bookings.h"
#include "Guests.h"
#include "Rooms.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ostream& operator<<(ostream& s, const Booking B)
{
	extern Guests* guests;
	s << B.room_ID + 1 << " ";
	s << guests->GetName(B.guest_ID) << " ";
	s << guests->GetSecName(B.guest_ID) << ", ";
	s << B.term;
	return s;
}

Booking::Booking(int r, int g)
{
	this->room_ID = r;
	this->guest_ID = g;
}

void Bookings::ReadConsole()
{
	extern Guests* guests;
	extern Rooms* rooms;

	cout << "ID pokoju: ";
	cin >> this->temp.room_ID;
	this->temp.room_ID--;
	cout << "Termin (dd/mm/rrrr-dd/mm/rrrr): ";
	cin >> this->temp.term;
	this->temp.guest_ID = guests->Add();
	rooms->AddTerm(this->temp.room_ID, this->temp.term);
	this->list.push_back(temp);
}

void Bookings::PrintAll()
{
	cout << "--- Nr pokoju --- imie --- nazwisko --- termin ---" << endl;
	for (auto i : this->list)
		cout << i << endl;
}

int Bookings::Find()
{
	int found = 0, it = 0;
	this->results = new int[int(this->list.size())];
	cout << "Numer drzwi pokoju: ";
	cin >> this->temp.room_ID;
	this->temp.room_ID--;
	cout << "Termin: ";
	cin >> this->temp.term;
	system("cls");
	
	cout << "Pasujace wyniki:" << endl << endl;

	for (auto i : this->list)
	{
		if (i.room_ID == this->temp.room_ID && i.term == this->temp.term)
		{
			results[found] = it;
			found++;
			cout << found << ". " << i << endl;
		}
		it++;
	}

	if (!found)
		cout << "Nie znaleziono pasujacych." << endl;

	return found;
}

void Bookings::Remove()
{
	extern Rooms* rooms;
	extern Guests* guests;
	int x;

	int c = this->Find();
	if (!c)
		return;
	cout << "Podaj pozycje do usuniecia: ";
	x = GetValue(1, c);
	x = this->results[x - 1];
	delete[] this->results;

	this->temp.guest_ID = this->list[x].guest_ID;
	this->temp.room_ID = this->list[x].room_ID;
	this->temp.term = this->list[x].term;
	this->list.erase(this->list.begin() + x);
	rooms->Remove(this->temp.room_ID, this->temp.term);
	guests->Remove();
}

void Bookings::ReadFile()
{
	cout << "Wczytywanie bazy rezerwacji... ";
	fstream file;
	file.open("Data files/bookings.txt", ios::in);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
		cout << "TU";
	while (!file.eof() && file >> this->temp.room_ID && file >> this->temp.guest_ID && file >> this->temp.term)
	{
		this->list.push_back(this->temp);
	}
	file.close();
	cout << "OK" << endl;
}

void Bookings::WriteFile()
{
	cout << "Zapisywanie bazy rezerwacji... ";
	fstream file;
	file.open("Data files/bookings.txt", ios::out);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
	for (auto i : this->list)
	{
		file << i.room_ID << " ";
		file << i.guest_ID << " ";
		file << i.term << endl;
	}
	file.close();
	cout << "OK" << endl;
}

void Bookings::Driver()
{
	Menu* menu = new Menu();
	menu->ListBooking();
	switch (menu->GetChoise(4))
	{
	case 0:

		return;

	case 1:

		cout << "--- Wyszukiwanie rezerwacji---" << endl << endl;
		this->Find();
		break;

	case 2:

		cout << "---Lista pokoi---" << endl << endl;
		this->PrintAll();
		break;

	case 3:

		cout << "---Dodawanie rezerwacji---" << endl << endl;
		this->ReadConsole();
		break;

	case 4:

		cout << "---Usuwanie rezerwacji---" << endl << endl;
		this->Remove();
		break;
	}
	PressAnyKey();
}

void Bookings::Today()
{
	cout << "Zaczynaja sie:" << endl;
	for (auto i : this->list)
	{
		if (i.term.Begins())
			cout << i << endl;
	}
	cout << endl << "Koncza sie" << endl;
	for (auto i : this->list)
	{
		if (i.term.Ends())
			cout << i << endl;
	}
}

double Bookings::GetPrice()
{
	extern Rooms* rooms;
	return this->temp.term.DaysBetween() * rooms->GetPrice(this->temp.room_ID);
}

int Bookings::GetGuestID()
{
	return this->temp.guest_ID;
}
