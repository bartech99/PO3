#pragma once
#include <iostream>
using namespace std;

/*
 * Klasa przechowuje wybory w menu oraz listy menu i podmenu.
 */

class Menu
{
    int choise; //wybor w menu

public:

    int Choise(); //pozwala jedynie odczytaæ zmienna choise poza klasa
    int GetChoise(int); //pobiera wybor

    void ListMain(); //menu glowne
    void ListGuest(); //podmenu gosci
    void ListRoom(); //podmenu pokoi
    void ListBooking(); //podmenu rezerwacji

    Menu(int = 0); //konstruktor
    ~Menu(); //destruktor
};

void PressAnyKey(); //wstrzymuje program do nacisniecia enter
int GetValue(int, int); //pobiera wartosc od do wart. arg. i zabezpiecza proces
double GetValue(double); //pobiera kwote od 0 do wart. arg. i zabezpiecza proces