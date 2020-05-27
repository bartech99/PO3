#include "Rooms.h"
#include "Menu.h"
#include "Term.h"
#include "Bookings.h"
#include <iostream>
#include <string>
#include <fstream>
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
	this->facilities.clear();
	this->terms.clear();
}

void Rooms::AddTerm(int x, Term term)
{
	if (x < 0 || x >= int(this->list.size()))
		return;
	this->list[x].terms.push_back(term);
}

void Rooms::Remove(int id, Term term)
{
	temp = this->list[id];
	unsigned int i = 0;
	while (i < temp.terms.size() && !(temp.terms[i] == term))
		i++;
	this->list[id].terms.erase(this->list[id].terms.begin() + i);
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
	for (unsigned int i = 0; i < this->list.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << this->list[i];
	}
}

int Rooms::Find()
{
	int found = 0;
	for (unsigned int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i].max_person >= this->temp.max_person)
		{
			if (this->list[i].terms.size() == 1)
			{
				if (this->list[i].terms[0] < this->tempTerm || this->list[i].terms[0] > this->tempTerm)
				{
					found++;
					cout << this->list[i];
				}
			}
			else if (this->list[i].terms.size() >= 2)
			{
				for (unsigned int j = 0; j < this->list[i].terms.size() - 1; i++)
				{
					if (this->list[i].terms[j] < this->tempTerm && this->list[i].terms[j + 1] > this->tempTerm)
					{
						found++;
						cout << this->list[i];
					}
				}
			}
		}
	}
	return found;
}

void Rooms::Remove()
{
	int id;
	cout << "Podaj numer drzwi pokoju: ";
	id = GetValue(1, this->list.size());
	this->list.erase(this->list.begin() + id - 1);
	cout << "Pokoj usuniety z bazy." << endl;
}

void Rooms::ReadFile()
{
	cout << "Wczytywanie bazy pokoi... ";
	fstream file;
	Term term;
	string line;
	file.open("Data files/rooms.txt", ios::in);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
	while (!file.eof() && file >> this->temp.name && file >> this->temp.price && file >> this->temp.max_person)
	{
		this->temp.facilities.clear();
		this->temp.terms.clear();
		int x;

		file >> x;
		for (int i = 0; i < x; i++)
		{
			file >> line;
			this->temp.facilities.push_back(line);
		}

		file >> x;
		for (int i = 0; i < x; i++)
		{
			term.StringToTerm(line);
			this->temp.terms.push_back(term);
			file >> line;
		}

		this->list.push_back(this->temp);
	}
	file.close();
	cout << "OK" << endl;
}

void Rooms::WriteFile()
{
	cout << "Zapisywanie bazy pokoi... ";
	fstream file;
	file.open("Data files/rooms.txt",ios::out);
	if (!file.good())
	{
		cout << "blad!" << endl;
		return;
	}
	for (auto i : this->list)
	{
		file << i.name << " ";
		file << i.price << " ";
		file << i.max_person << endl;

		file << i.facilities.size() << " ";
		for (auto j : i.facilities)
			file << j << " ";
		file << endl;

		file << i.terms.size() << " ";
		for (auto j : i.terms)
			file << j << " ";
		file << endl;
	}
	file.close();
	cout << "OK" << endl;
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

		cout << "--- Wyszukiwanie pokoju---" << endl << endl;
		cout << "Podaj ilosc osob do zameldowania: ";
		this->temp.max_person = GetValue(1, 20);
		cout << "Podaj termin: ";
		cin >> this->tempTerm;
		system("cls");
		cout << "Pasujace wyniki:" << endl << endl;
		if (!this->Find())
			cout << "Nie znaleziono pasujacych." << endl;
		break;

	case 2:

		cout << "---Lista pokoi---" << endl << endl;
		this->PrintAll();
		break;

	case 3:

		cout << "--- Dodawanie pokoju---" << endl << endl;
		this->ReadConsole();
		break;

	case 4:

		cout << "--- Usuwanie pokoju---" << endl << endl;
		this->Remove();
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