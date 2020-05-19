#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Database
{
public:

	virtual void ReadConsole() = 0;
	virtual void PrintAll() = 0;
	virtual int Find() = 0;
	virtual void Remove() = 0;
	virtual void ReadFile() = 0;
	virtual void WriteFile() = 0;
	virtual void Driver() = 0;
};