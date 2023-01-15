#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

enum tipZona { Necunoscuta, Peluza, Tribuna1, Tribuna2, Normal, VIP, Categoria1, Categoria2, Loja };
class Loc
{
private:
	int rand;
	int nr_loc;
	bool ocupat;
	tipZona zona;

public:
	Loc()
	{
		rand = 0;
		nr_loc = 0;
		ocupat = 0;
		zona = tipZona::Necunoscuta;
	}

	Loc(int rand, int nr_loc, bool ocupat, tipZona zona)
	{
		this->rand = rand;
		this->nr_loc = nr_loc;
		this->ocupat = ocupat;
		this->zona = zona;
	}

	//Constructor de copiere
	Loc(const Loc& L)
	{
		this->rand = L.rand;
		this->nr_loc = L.nr_loc;
		this->ocupat = L.ocupat;
		this->zona = L.zona;
	}

	//Metoda Vizibilitate
	void Vizibilitate(int rand)
	{
		if (this->rand <= 4)
			cout << "Cea mai buna vizibilitate";
		if (this->rand > 4 && this->rand <= 6)
			cout << "Vizibilitate medie";
		if (this->rand > 6)
			cout << "Vizibilitate redusa";
	}

	//Metoda Zona
	void Zona(tipZona zona)
	{
		if (zona == Peluza || zona == Tribuna1 || zona == Tribuna2)
			cout << "In Zona " << zona << " are loc un meci de fotbal.";
		if (zona == Normal || zona == VIP)
			cout << "In Zona " << zona << " se deruleaza un film.";
		if (zona == Categoria1 || zona == Categoria2 || zona == Loja)
			cout << "In Zona " << zona << " este pusa in scena o piesa de teatru.";
	}

	//Metoda ocupare obiect de tip loc cu parametru obiect de tip loc
	void ocupaLoc(Loc l, int m, int n)
	{
		if (l.ocupat == 0)
		{
			l.ocupat = 1;
			cout << "Locul a fost ocupat!";
		}
		else
			cout << "Locul este deja ocupat!";
	}

	//Loc ocupaLocul(Loc l)
	//{
	//	Loc locNou;
	//locNou.rand = l.rand;
	//locNou.nr_loc = l.nr_loc;
	//locNou.zona = l.zona;
	//locNou.ocupat = 1;
	//return locNou;
	//	}
	//

	//rand-------------
	int getRand()
	{
		return this->rand;
	}

	void setRand(int rand)
	{
		this->rand = rand;
	}

	//nr_loc-------------
	int getNr_loc()
	{
		return this->nr_loc;
	}

	void setNr_loc(int nr_loc)
	{
		this->nr_loc = nr_loc;
	}

	//ocupat-------------
	bool getOcupat()
	{
		return ocupat;
	}

	//setter disponibilitate
	void setOcupat(bool ocupat)
	{
		this->ocupat = ocupat;
	}

	//zona-------------
	tipZona getZona()
	{
		return this->zona;
	}

	void setZona(tipZona zona)
	{
		this->zona = zona;
	}

	//Supraincarcare ++
	Loc operator++()
	{
		this->rand++;
		return *this;
	}

	//Supraincarcare --
	Loc operator--()
	{
		this->rand--;
		return *this;
	}

	////Supraincarcare =
	//Loc& operator=(const Loc& L)
	//{
	//	this->rand = L.rand;
	//	this->nr_loc = L.nr_loc;
	//	this->ocupat = L.ocupat;
	//	this->zona = zona;
	//}

	friend istream& operator>>(istream& in, Loc& L)
	{
		in >> L.rand >> L.nr_loc >> L.ocupat;
		//citeste zona de tip enum
		char buffer[20];
		in >> buffer;
		if (strcmp(buffer, "Peluza") == 0)
			L.zona = tipZona::Peluza;
		if (strcmp(buffer, "Tribuna1") == 0)
			L.zona = tipZona::Tribuna1;
		if (strcmp(buffer, "Tribuna2") == 0)
			L.zona = tipZona::Tribuna2;
		if (strcmp(buffer, "Normal") == 0)
			L.zona = tipZona::Normal;
		if (strcmp(buffer, "VIP") == 0)
			L.zona = tipZona::VIP;
		if (strcmp(buffer, "Categoria1") == 0)
			L.zona = tipZona::Categoria1;
		if (strcmp(buffer, "Categoria2") == 0)
			L.zona = tipZona::Categoria2;
		if (strcmp(buffer, "Loja") == 0)
			L.zona = tipZona::Loja;
		
		return in;
	}
};


ostream& operator<<(ostream& out, Loc L)
{
	out << L.getRand() << " " << L.getNr_loc() << " " << L.getOcupat() << " " << L.getZona()  << endl;
	return out;
}
