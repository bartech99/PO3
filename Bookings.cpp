#include "Bookings.h"
#include "Rooms.h"
#include "Guests.h"
#include "Menu.h"
#include <iostream>
using namespace std;

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
}

void Bookings::PrintAll()
{
}

int Bookings::Find()
{
	return 0;
}
