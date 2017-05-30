#include "stdafx.h"
#include "Neuron.h"
#include "math.h"

double Neuron::danaWejsciowa[][4];
double Neuron::m_wynik;
double Neuron::danaOczekiwana = 0;
Neuron::Stan Neuron::dzialanie = Neuron::BRAK;

Neuron::Neuron()
{
}


Neuron::~Neuron()
{
}

double Neuron::losujLiczbe()
{
	double wylosowanaLiczba;
	do
	{
		//wylosowanaLiczba = (1.0 * rand() / (100000)); dziele przez wiecej i mnoze przez druga aby byla wieksza losowosc
		wylosowanaLiczba = (2.0 * rand() / (1000000)) * (1.0 * rand() / (1000)) - 0.5;
	} while (wylosowanaLiczba > 0.9 && wylosowanaLiczba < -0.9);

	return wylosowanaLiczba;
}

void Neuron::dzialaj(bool losowanie, int warstwa)
{
	double wyjscie = 0;
	//wejscie losujace
	if (losowanie)
	{
		for (int i = 0; i < 4; i++)
		{
			wagi[i] = losujLiczbe();
		}
	}

	//wejscie bez losowania
	//#######################

	m_sumator = sumator(warstwa);
	m_aktywator = aktywator();
	this->m_wyjscie = m_aktywator;
	if (warstwa == 2)
		this->m_wynik = this->m_wyjscie;
}

double Neuron::sumator(int warstwa)
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

double Neuron::aktywator()
{
	double wynikTanges = 0;
	double licznik = 0;
	double mianownik = 0;
	double wynikTangesPochodna = 0;


	//liczymy tangens hiperboliczny, tan(h)
	licznik = exp(m_sumator) - exp(-m_sumator);
	mianownik = exp(m_sumator) + exp(-m_sumator);
	wynikTanges = licznik / mianownik;

	//liczymy pochodn¹ tan(h)
	wynikTangesPochodna = 1 - (wynikTanges * wynikTanges);

	return wynikTanges;
}

void Neuron::setDaneWejsciowe()
{
	cout << endl;
	cout << "Podaj x1: ";
	cin >> danaWejsciowa[0][0];
	cout << "Podaj x2: ";
	cin >> danaWejsciowa[0][1];
	//bies = 1;
	danaWejsciowa[0][2] = 1;

	cout << "\nPodaj wynik: ";
	cin >> danaOczekiwana;
}

void Neuron::menu()
{
	int klawisz = 0;

	cout << "\nMoze nauka?\n\n";
	cout << " 1 - Uczymy sie \n";
	cout << " 2 - Dzialamy \n";

	cin >> klawisz;
	if (klawisz == 1)
	{
		Neuron::dzialanie = Neuron::Stan::UCZY_SIE;
	}
	else if (klawisz == 2)
	{
		Neuron::dzialanie = Neuron::Stan::DZIALA;
	}
	system("cls");
}

double Neuron::getWyjscie()
{
	return m_wyjscie;
}

double Neuron::getWynik()
{
	return m_wynik;
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
	cout << m_sumator << endl;

	cout << "\n===============\n";
	cout << "Aktywator:\n";
	cout << m_aktywator << endl;
	
}
