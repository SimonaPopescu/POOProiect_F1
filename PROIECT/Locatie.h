#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

enum tipLocatiee { Implicit, Fotbal, Film, Teatru };
class Locatie
{
private:
	int nr_randuri;
	int nr_locuri_rand;
	tipLocatiee tipLocatie;

public:
	Locatie()
	{
		nr_randuri = 0;
		nr_locuri_rand = 0;
		tipLocatie = tipLocatiee::Implicit;
	}

	Locatie(int nr_randuri, int nr_locuri_rand, tipLocatiee tipLocatie)
	{
		this->nr_randuri = nr_randuri;
		this->nr_locuri_rand = nr_locuri_rand;
		this->tipLocatie = tipLocatie;
	}

	//Constructor de copiere-----
	Locatie(const Locatie& L)
	{
		nr_randuri = L.nr_randuri;
		nr_locuri_rand = L.nr_locuri_rand;
		tipLocatie = L.tipLocatie;
	}

	//Metoda Capacitate
	void capacitateLocatie(int nr_randuri, int nr_locuri_rand)
	{
		int x;
		x = this->nr_randuri * this->nr_locuri_rand;
		cout << "Capacitatea locatiei este: " << x;
	}

	//Metoda afisare disponibilitate
	void afisareDisponibilitate(tipLocatiee locatie, int nr_randuri, int nr_locuri_rand)
	{
		cout << "Pentru evenimentul de tip " << locatie << " sunt disponibile initial: " << endl;
		cout << "Numar de randuri: " << nr_randuri << endl;
		cout << "Numar de locuri pe rand: " << nr_locuri_rand << endl;
	}


	//nr_randuri-----------
	int getNr_randuri()
	{
		return nr_randuri;
	}

	void setNr_randuri(const int nr_rand)
	{
		if (nr_rand != 0)
			nr_randuri = nr_rand;
	}


	//nr_locuri_rand--------
	int getNr_locuri_rand()
	{
		return nr_locuri_rand;
	}

	void setNr_locuri_rand(const int nr_loc)
	{
		if (nr_loc != 0)
			nr_locuri_rand = nr_loc;
	}

	//locatie----------------
	tipLocatiee getTipLocatie()
	{
		return tipLocatie;
	}

	void setTipLocatie(tipLocatiee l)
	{
		if (l)
			tipLocatie = l;
	}

	Locatie& operator=(const Locatie& L)
	{
		this->nr_randuri = L.nr_randuri;
		this->nr_locuri_rand = L.nr_locuri_rand;
		this->tipLocatie = L.tipLocatie;
	}

	//Supraincarcare +
	Locatie operator+()
	{
		this->nr_randuri = nr_randuri + 2;
		return *this;
	}

	//Supraincarcare -
	Locatie operator-()
	{
		if (this->nr_randuri >= 2)
			this->nr_randuri = nr_randuri - 2;
		return *this;
	}


	friend istream& operator>>(istream& in, Locatie& L)
	{
		cout << "Numarul de randuri este: ";
		in >> L.nr_randuri;
		cout << "Numarul de locuri pe rand este: ";
		in >> L.nr_locuri_rand;
		string l;
		in >> l;
		if (l == "Implicit")
			L.tipLocatie = Implicit;
		if (l == "Fotbal")
			L.tipLocatie = Fotbal;
		if (l == "Film")
			L.tipLocatie = Film;
		if (l == "Film")
			L.tipLocatie = Film;
		return in;
	}

};


ostream& operator<<(ostream& out, Locatie L2)
{
	out << "Numarul de randuri este: " << L2.getNr_randuri() << endl;
	out << "Numarul de locuri pe rand este: " << L2.getNr_locuri_rand() << endl;
	switch (L2.getTipLocatie())
	{
	case 0: out << "Tipul locatiei este: Implicit" << endl;
		break;
	case 1: out << "Tipul locatiei este: Fotbal" << endl;
		break;
	case 2: out << "Tipul locatiei este: Film" << endl;
		break;
	case 3: out << "Tipul locatiei este: Teatru" << endl;
		break;
	}
	return out;
}
