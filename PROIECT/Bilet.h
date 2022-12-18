#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Locatie.h"
#include "Loc.h"
#include "Eveniment.h"
using namespace std;

class Bilet
{
private:
	int id_bilet;
	float pret;
	Loc loc_bilet; //!!!! afisare tiparie bilet
	Eveniment event;

public:
	Bilet()
	{
		id_bilet = 0;
		pret = 0;
	}

	Bilet(int id_bilet, Loc loc_bilet, Eveniment event)
	{
		this->id_bilet = id_bilet;
		this->loc_bilet = loc_bilet;
		this->event = event;
		//FILM-PRETURI-------
		if (loc_bilet.getZona() == tipZona::VIP)
		{
			this->pret = 70;
		}
		if (loc_bilet.getZona() == tipZona::Normal)
		{
			this->pret = 25;
		}

		//TEATRU-PRETURI-----
		if (loc_bilet.getZona() == tipZona::Loja)
		{
			this->pret = 90;
		}
		if (loc_bilet.getZona() == tipZona::Categoria1)
		{
			this->pret = 80;
		}
		if (loc_bilet.getZona() == tipZona::Categoria2)
		{
			this->pret = 65;
		}

		//FOTBAL-PRETURI-----
		if (loc_bilet.getZona() == tipZona::Peluza)
		{
			this->pret = 150;
		}
		if (loc_bilet.getZona() == tipZona::Tribuna1)
		{
			this->pret = 210;
		}
		if (loc_bilet.getZona() == tipZona::Tribuna2)
		{
			this->pret = 185;
		}
	}

	//Metoda Discount
	int Discount(float pret, string discount, Loc loc_bilet)
	{
		cin >> discount;
		cout << "Discount-ul pentru biletul de " << discount << " este de 20%.";
		pret = pret - pret * 20 / 100;
		return pret;
	}

	//Metoda codReducere
	void codReducere(string nume)
	{
		cin >> nume;
		if (nume == "Popescu")
			cout << "Codul de reducere este POPESCU58";
	}


	//id_bilet----------
	int getId_bilet()
	{
		return id_bilet;
	}

	void setId_bilet(const int id_bil)
	{
		if (id_bilet != 0)
			id_bilet = id_bil;
	}

	//pret-------------
	float getPret()
	{
		return pret;
	}

	void setPret(const float p)
	{
		if (pret != 0)
			pret = p;
	}

	//loc_bilet--------
	Loc getLoc_bilet()
	{
		return loc_bilet;
	}

	//event------------
	Eveniment getEvent()
	{
		return event;
	}

	//Supraincarcare *
	Bilet operator*()
	{
		this->pret = pret * 2;
		return *this;
	}

	//Supraincarcare /
	Bilet operator/(float pret)
	{
		pret = pret / 10;
	}

	friend istream& operator>>(istream& in, Bilet& B)
	{
		cout << "ID-ul biletului este: ";
		in >> B.id_bilet;

		cout << "Pretul biletului este: ";
		in >> B.pret;

		cout << "Localizarea este: ";
		in >> B.loc_bilet;

		cout << "Detaliile evenimentului sunt: ";
		in >> B.event;

		return in;
	}
};


ostream& operator<<(ostream& out, Bilet B)
{
	out << "ID-ul biletului este: " << B.getId_bilet() << endl;
	out << "Pretul biletului este: " << B.getPret() << endl;
	out << "Numarul randului: " << B.getLoc_bilet().getRand() << endl;
	out << "Numarul locului: " << B.getLoc_bilet().getNr_loc() << endl;
	out << "Zona este: " << B.getLoc_bilet().getZona() << endl;
	out << "Zona este: " << B.getLoc_bilet().getZona() << endl;
	return out;
}
