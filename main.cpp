#include <iostream>
#include "Bookings.h"
#include "Database.h"
#include "Guests.h"
#include "Menu.h"
#include "Rooms.h"
#include "Term.h"
using namespace std;

int main()
{
	Rooms* R = new Rooms;
	R->ReadConsole();
	R->PrintAll();
	return 0;
}
