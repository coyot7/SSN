#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Neuron
{
private:
	double wagi[4];
	double sumator;
	double aktywator;
	double wyjscie;
	const int warstwaZero = 3;
	const int warstwaJeden = 4;
	const int warstwaDwa = 3;
	static double wynik;

	static double danaWejsciowa[3][4]; //warstwa, liczba neuronów

public:
	Neuron();
	~Neuron();
	
	void Dzialaj(bool losowanie, int warstwa);
	double Sumator(int warstwa);
	double Aktywator();
	double getWyjscie();
	
	static double getWynik();
	static double LosujLiczbe();
	static void SetDaneWejsciowe();
	static void setDanaWejsciowa(int warstwa, int neuron, double dana);

	void DisplayMatrix(int warstwa, int neuron);
};

