#include "Guests.h"
#include <iostream>
using namespace std;

bool Guest::operator==(const Guest arg)
{
	if (arg.name == this->name && arg.secName == this->secName)
		return true;
	else
		return false;
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
}

int Guests::Find()
{
	return 0;
}