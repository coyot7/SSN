#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	static void init();
	static void run();
	static void MaszynaLosujacaStart();
	
};

