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
		ocupat = 0;
		this->zona = zona;
	}

	//Constructor de copiere
	Loc(const Loc& L)
	{
		rand = L.rand;
		nr_loc = L.nr_loc;
		ocupat = L.ocupat;
		zona = L.zona;
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

	//rand-------------
	int getRand()
	{
		return rand;
	}

	void setRand(const int rrr)
	{
		if (rrr != 0)
			rand = rrr;
	}

	//nr_loc-------------
	int getNr_loc()
	{
		return nr_loc;
	}

	void setNr_loc(const int nl)
	{
		if (nl != 0)
			nr_loc = nl;
	}

	//ocupat-------------
	bool getOcupat()
	{
		return ocupat;
	}

	void setOcupat(const bool o)
	{
		if (o)
			ocupat = o;
	}

	//zona-------------
	tipZona getZona()
	{
		return zona;
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

	//Supraincarcare =
	Loc& operator=(const Loc& L)
	{
		this->rand = L.rand;
		this->nr_loc = L.nr_loc;
		this->ocupat = L.ocupat;
		this->zona = zona;
	}

	friend istream& operator>>(istream& in, Loc& L)
	{
		cout << "Randul este: ";
		in >> L.rand;
		cout << "Numarul locului este: ";
		in >> L.nr_loc;
		cout << "Disponibilitate: ";
		in >> L.ocupat;
		string z;
		in >> z;
		if (z == "Necunoscuta")
			L.zona = Necunoscuta;
		if (z == "Peluza")
			L.zona = Peluza;
		if (z == "Tribuna1")
			L.zona = Tribuna1;
		if (z == "Tribuna2")
			L.zona = Tribuna2;
		if (z == "Normal")
			L.zona = Normal;
		if (z == "VIP")
			L.zona = VIP;
		if (z == "Categoria1")
			L.zona = Categoria1;
		if (z == "Categoria2")
			L.zona = Categoria2;
		if (z == "Loja")
			L.zona = Loja;
		return in;
	}
};


ostream& operator<<(ostream& out, Loc L)
{
	out << "Rand: " << L.getRand() << endl;
	out << "Numar loc: " << L.getNr_loc() << endl;
	switch (L.getZona())
	{
	case 0: out << "Zona: Necunoscuta" << endl;
		break;
	case 1: out << "Zona: Peluza" << endl;
		break;
	case 2: out << "Zona: Tribuna 1" << endl;
		break;
	case 3: out << "Zona: Tribuna 2" << endl;
		break;
	case 4: out << "Zona: Normal" << endl;
		break;
	case 5: out << "Zona: VIP" << endl;
		break;
	case 6: out << "Zona: Categoria 1" << endl;
		break;
	case 7: out << "Zona: Categoria 2" << endl;
		break;
	case 8: out << "Zona: Loja" << endl;
		break;
	}
	out << "Disponibilitate: ";
	if (L.getOcupat() == 0)
		out << "Disponibil";
	else
		out << "Ocupat";
	return out;
}
