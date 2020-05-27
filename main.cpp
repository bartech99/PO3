#include <iostream>
#include "Bookings.h"
#include "Guests.h"
#include "Rooms.h"
#include "Menu.h"
#include "Term.h"
using namespace std;

Rooms* rooms;
Bookings* bookings;
Guests* guests;

int main()
{
	rooms = new Rooms();
	bookings = new Bookings();
	guests = new Guests();
	
	Menu* menu = new Menu();
	while (true)
	{
		menu->ListMain();
		switch (menu->GetChoise(6))
		{
		case 0:

			cout << "Koniec pracy programu. Zapisac wyniki w plikach? t/n: ";
			char check;
			cin >> check;
			if (check != 'n')
			{
				rooms->WriteFile();
				guests->WriteFile();
				bookings->WriteFile();
			}
			return 0;

		case 1:

			guests->Driver();
			break;

		case 2:

			rooms->Driver();
			break;

		case 3:

			bookings->Driver();
			break;

		case 4:
			
			cout << "--- Dziennik ---" << endl;
			bookings->Today();
			PressAnyKey();
			break;

		case 5:

			delete rooms;
			delete guests;
			delete bookings;
			rooms = new Rooms();
			bookings = new Bookings();
			guests = new Guests();

			rooms->ReadFile();
			guests->ReadFile();
			bookings->ReadFile();
			PressAnyKey();
			break;

		case 6:

			rooms->WriteFile();
			guests->WriteFile();
			bookings->WriteFile();
			PressAnyKey();
			break;
		}
	}
}