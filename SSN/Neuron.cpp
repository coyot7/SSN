#include "stdafx.h"
#include "Neuron.h"
#include "math.h"

double Neuron::danaWejsciowa[][4];
double Neuron::wynik;

Neuron::Neuron()
{
}


Neuron::~Neuron()
{
}

double Neuron::LosujLiczbe()
{
	double wylosowanaLiczba;
	do
	{
		//wylosowanaLiczba = (1.0 * rand() / (100000)); dziele przez wiecej i mnoze przez druga aby byla wieksza losowosc
		wylosowanaLiczba = (2.0 * rand() / (1000000)) * (1.0 * rand() / (1000)) - 0.5;
	} while (wylosowanaLiczba > 0.9 && wylosowanaLiczba < -0.9);

	return wylosowanaLiczba;
}

void Neuron::Dzialaj(bool losowanie, int warstwa)
{
	double wyjscie = 0;
	//wejscie losujace
	if (losowanie)
	{
		for (int i = 0; i < 4; i++)
		{
			wagi[i] = LosujLiczbe();
		}
	}

	//wejscie bez losowania
	//#######################

	sumator = Sumator(warstwa);
	aktywator = Aktywator();
	this->wyjscie = aktywator;
	if (warstwa == 2)
		this->wynik = this->wyjscie;
}

double Neuron::Sumator(int warstwa)
{
	double wynik = 0;

	if (warstwa == 0)
	{
		for (int i = 0; i < warstwaZero; i++)
		{
			wynik += danaWejsciowa[warstwa][i] * wagi[i];
		}
	}

	else if (warstwa == 1)
	{
		for (int i = 0; i < warstwaJeden; i++)
		{
			wynik += danaWejsciowa[warstwa][i] * wagi[i];
		}
	}

	else if (warstwa == 2)
	{
		for (int i = 0; i < warstwaDwa; i++)
		{
			wynik += danaWejsciowa[warstwa][i] * wagi[i];
		}
	}

	return wynik;
}

double Neuron::Aktywator()
{
	double wynik = 0;
	double licznik = 0;
	double mianownik = 0;

	licznik = exp(sumator) - exp(-sumator);
	mianownik = exp(sumator) + exp(-sumator);
	wynik = licznik / mianownik;

	return wynik;
}

void Neuron::SetDaneWejsciowe()
{
	cout << endl;
	cout << "Podaj x1: ";
	cin >> danaWejsciowa[0][0];
	cout << "Podaj x2: ";
	cin >> danaWejsciowa[0][1];
	//bies = 1;
	danaWejsciowa[0][2] = 1;
}

double Neuron::getWyjscie()
{
	return wyjscie;
}

double Neuron::getWynik()
{
	return wynik;
}

void Neuron::setDanaWejsciowa(int warstwa, int neuron, double dana)
{
	danaWejsciowa[warstwa][neuron] = dana;
}

void Neuron::DisplayMatrix(int warstwa, int neuron)
{
	cout << "\n===============\n";
	cout << "Warstwa: " << warstwa << ", Neuron: " << neuron;
	cout << "\n===============\n";

	cout << "\n===============\n";
	cout << "Wejscie:\n";
	if (warstwa == 0)
	{
		for (int i = 0; i < warstwaZero; i++)
		{
			cout << danaWejsciowa[warstwa][i] << endl;
		}
	}

	else if (warstwa == 1)
	{
		for (int i = 0; i < warstwaJeden; i++)
		{
			cout << danaWejsciowa[warstwa][i] << endl;
		}
	}

	else if (warstwa == 2)
	{
		for (int i = 0; i < warstwaDwa; i++)
		{
			cout << danaWejsciowa[warstwa][i] << endl;
		}
	}

	cout << "\n===============\n";
	cout << "Wagi:\n";
	if (warstwa == 0)
	{
		for (int i = 0; i < warstwaZero; i++)
		{
			cout << wagi[i] << endl;
		}
	}

	else if (warstwa == 1)
	{
		for (int i = 0; i < warstwaJeden; i++)
		{
			cout << wagi[i] << endl;
		}
	}

	else if (warstwa == 2)
	{
		for (int i = 0; i < warstwaDwa; i++)
		{
			cout << wagi[i] << endl;
		}
	}

	cout << "\n===============\n";
	cout << "Sumator:\n";
	cout << sumator << endl;

	cout << "\n===============\n";
	cout << "Aktywator:\n";
	cout << aktywator << endl;
	
}
