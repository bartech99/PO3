#include "Menu.h"
#include <iostream>
#include <conio.h>
using namespace std;

int Menu::Choise()
{
	return this->choise;
}

int Menu::GetChoise(int max)
{
	cout << "Twoj wybor: ";
	this->choise = GetValue(0, max);
	cout << endl;
	return this->choise;
}

void Menu::ListMain()
{
	system("cls");
	cout << "--- MENU GLOWNE ---" << endl << endl;
	cout << "1. Zarzadzanie baza gosci" << endl;
	cout << "2. Zarzadzanie baza pokoi" << endl;
	cout << "3. Zarzadzanie baza rezerwacji" << endl;
	cout << "4. Dziennik" << endl; //rezerwacje zaczynajace sie i konczace dzisiaj
	cout << "5. Wczytaj baze z pliku" << endl;
	cout << "6. Zapisz baze w pliku" << endl;
	cout << "0. Zakoncz program" << endl << endl;
}

void Menu::ListGuest()
{
	system("cls");
	cout << "--- Menu gosci ---" << endl << endl;
	cout << "1. Sprawdz rachunek goscia" << endl; //po wprowadzeniu imienia i nazwiska, pokazuje szczegoly gosci
	cout << "2. Wyswietl wszystkich gosci" << endl; //lista wszystkich gosci
	cout << "3. Pobierz oplate" << endl; //odlicza dana kwote z salda goscia (zamiast dodaj i usun)
	cout << "0. Powrot do menu glownego" << endl << endl;
}

void Menu::ListRoom()
{
	system("cls");
	cout << endl << "--- Menu pokoi ---" << endl << endl;
	cout << "1. Znajdz i wyswietl szczegoly pokoju" << endl; //po wprowadzeniu nazwy, pokazuje pasujace ze szczegolami
	cout << "2. Wyswietl wszystkie pokoje" << endl; //lista wszystkich pokoi
	cout << "3. Dodaj pokoj" << endl; //pozwala wprowadzic kolejny pokoj
	cout << "4. Usun pokoj" << endl; //po wprowadzeniu nazwy pokoju, pokazuje pasujace i usuwa wybrany
	cout << "0. Powrot do menu glownego" << endl << endl;
}

void Menu::ListBooking()
{
	system("cls");
	cout << "--- Menu rezerwacji ---" << endl << endl;
	cout << "1. Znajdz i wyswietl szczegoly rezerwacji" << endl; //po wprowadzeniu imienia i nazwiska, pokazuje szczegoly
	cout << "2. Wyswietl wszystkie rezerwacje" << endl; //lista wszystkich 
	cout << "3. Dokonaj rezerwacji" << endl; //po wprowadzeniu terminu, pokazuje dostepne pokoje
	cout << "4. Usun rezerwacje" << endl; //po wprowadzeniu imienia i nazwiska, pokazuje pasujace i usuwa wybrana
	cout << "0. Powrot do menu glownego" << endl << endl;
}

Menu::Menu(int c)
{
	this->choise = c;
}

Menu::~Menu()
{
}

void PressAnyKey()
{
	cout << endl << "Nacisnij dowolny przycisk, aby kontynuowac..." << endl;
	_getch();
	system("cls");
}

int GetValue(int min, int max)
{
	int v;

	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}

	while (true)
	{
		if (!(cin >> v) || v < min || v > max)
		{
			cin.clear();
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Blad! Jeszcze raz: " << endl;
		}
		else break;
	}
	return v;
}

double GetValue(double max)
{
	double v;

	while (true)
	{
		if (!(cin >> v) || v < 0.0 || v > max)
		{
			cin.clear();
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Blad! Jeszcze raz: ";
		}
		else break;
	}
	return v;
}