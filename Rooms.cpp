#include "Rooms.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

void Room::GetFacilities(string line)
{
	string temp = "";
	for (unsigned int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			this->facilities.push_back(temp);
			temp = "";
		}
		else
		{
			temp += line[i];
		}
	}
	this->facilities.push_back(temp);
}

ostream& operator<<(ostream& s, const Room R)
{
	s << R.name << ": ";
	s << R.price << "zl/noc, ";
	s << R.max_person << "os." << endl;
	s << "\tUdogodnienia: ";
	for (unsigned int i = 0; i < R.facilities.size(); i++)
		s << R.facilities[i] << ", ";
	if (R.terms.size())
	{
		s << endl << "\tZarezerwowany: ";
		for (unsigned int i = 0; i < R.terms.size(); i++)
			s << R.terms[i] << ", ";
		s << endl;
	}
	s << endl;
	return s;
}

Room::Room(string n, double p, int m)
{
	this->name = n;
	this->price = p;
	this->max_person = m;
}

Room::~Room()
{
}

void Rooms::AddTerm(int x, Term term)
{
	if (x < 0 || x >= int(this->list.size()))
		return;
	this->list[x - 1].terms.push_back(term);
}

void Rooms::ReadConsole()
{
	Room temp;
	cout << "Nazwa pokoju: ";
	cin >> temp.name;
	cout << "Cena za pokoj za noc: ";
	temp.price = GetValue(1000.0);
	cout << "Maksymalna ilosc osob: ";
	temp.max_person = GetValue(1,20);
	cout << "Udogonienia (po spacji): ";
	string lines;
	cin.ignore();
	getline(cin, lines);
	temp.GetFacilities(lines);
	this->list.push_back(temp);
}

void Rooms::PrintAll()
{
	for (auto i : this->list)
		cout << i << endl;
}

int Rooms::Find()
{
	return 0;
}

void Rooms::Remove()
{
}

void Rooms::ReadFile()
{
}

void Rooms::WriteFile()
{
}

void Rooms::Driver()
{
	Menu* menu = new Menu();
	menu->ListRoom();
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

double Rooms::GetPrice(int pos)
{
	if (int(this->list.size()) <= pos)
		return 0.0;
	else
		return this->list[pos].price;
}