#include "Bookings.h"
#include "Guests.h"
#include "Rooms.h"
#include "Menu.h"
#include <iostream>
#include <string>
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

Booking::~Booking()
{
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
	return 0;
}

void Bookings::Remove()
{
}

void Bookings::ReadFile()
{
}

void Bookings::WriteFile()
{
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

		break;

	case 2:

		this->PrintAll();
		break;

	case 3:

		this->ReadConsole();
		break;

	case 4:

		break;
	}
	PressAnyKey();
}

double Bookings::GetPrice()
{
	extern Rooms* rooms;
	return this->temp.term.DaysBetween() * rooms->GetPrice(this->temp.room_ID);
}