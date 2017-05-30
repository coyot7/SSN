#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Neuron
{
private:
	double wagi[4];
	double m_sumator;
	double m_aktywator;
	double m_pochodnaAktywatora;
	double m_wyjscie;
	const int warstwaZero = 3;
	const int warstwaJeden = 4;
	const int warstwaDwa = 3;
	static double m_wynik;

	static double danaWejsciowa[3][4]; //warstwa, liczba neuronów
	static double danaOczekiwana;


public:
	Neuron();
	~Neuron();

	enum Stan
	{
		BRAK,
		UCZY_SIE,
		DZIALA,
	};
	
	void dzialaj(bool losowanie, int warstwa);
	double sumator(int warstwa);
	double aktywator();
	double getWyjscie();
	
	static void menu();
	static double getWynik();
	static double losujLiczbe();
	static void setDaneWejsciowe();
	static void setDanaWejsciowa(int warstwa, int neuron, double dana);
	static Stan dzialanie;

	void DisplayMatrix(int warstwa, int neuron);
};

