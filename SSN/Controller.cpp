#include "stdafx.h"
#include "Controller.h"
#include "Neuron.h"

Neuron warstwa0_neruron0;
Neuron warstwa0_neruron1;
Neuron warstwa0_neruron2;

Neuron warstwa1_neruron0;
Neuron warstwa1_neruron1;
Neuron warstwa1_neruron2;

Neuron wynik;

Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::MaszynaLosujacaStart()
{
	srand((unsigned int)time(NULL));
}


void Controller::init()
{
	MaszynaLosujacaStart();
}

void Controller::run()
{
	Neuron::menu();

	Neuron::setDaneWejsciowe();


	warstwa0_neruron0.dzialaj(true, 0);
	Neuron::setDanaWejsciowa(1, 0, warstwa0_neruron0.getWyjscie());
	warstwa0_neruron0.DisplayMatrix(0, 0);

	warstwa0_neruron1.dzialaj(true, 0);
	Neuron::setDanaWejsciowa(1, 1, warstwa0_neruron1.getWyjscie());
	warstwa0_neruron1.DisplayMatrix(0, 1);

	warstwa0_neruron2.dzialaj(true, 0);
	Neuron::setDanaWejsciowa(1, 2, warstwa0_neruron2.getWyjscie());
	warstwa0_neruron2.DisplayMatrix(0, 2);
	
	//bies
	Neuron::setDanaWejsciowa(1, 3, 1);


	warstwa1_neruron0.dzialaj(true, 1);
	Neuron::setDanaWejsciowa(2, 0, warstwa1_neruron0.getWyjscie());
	warstwa1_neruron0.DisplayMatrix(1, 0);

	warstwa1_neruron1.dzialaj(true, 1);
	Neuron::setDanaWejsciowa(2, 1, warstwa1_neruron1.getWyjscie());
	warstwa1_neruron1.DisplayMatrix(1, 1);

	//bies
	Neuron::setDanaWejsciowa(2, 2, 1);

	wynik.dzialaj(true, 2);
	wynik.DisplayMatrix(2, 0);

	cout << "\nWynik: " << Neuron::getWynik() << endl;
}
