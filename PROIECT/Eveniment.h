#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Locatie.h"
#include "Loc.h"
using namespace std;

class Eveniment
{
private:
	char* adresa;
	char* nume_eveniment;
	string data;
	string ora;
	Locatie locatie;
	Loc** locuri_ocupate;
	static string agentie;

public:
	Eveniment()
	{
		char* adresa = new char[100];
		strcpy_s(adresa, 1, "");
		char* nume_eveniment = new char[100];
		strcpy_s(nume_eveniment, 1, "");
		data = "Necunoscuta";
		ora = "Necunoscuta";
	}

	Eveniment(char* adresa, char* nume_eveniment, string data, string ora, Locatie locatie, Loc** locuri_o)
	{
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
		this->data = data;
		this->ora = ora;
		this->locatie = locatie;
		Loc** locuri_ocupate = new Loc * [locatie.getNr_randuri() * locatie.getNr_locuri_rand()];
		for (int i = 0; i < locatie.getNr_randuri(); i++)
		{
			for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
			{
				locuri_ocupate[i][j].setRand(i + 1);
				locuri_ocupate[i][j].setNr_loc(j + 1);
				locuri_ocupate[i][j].setOcupat(0);
			}
		}
		//FILM---------
		if (locatie.getTipLocatie() == tipLocatiee::Film)
		{
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					if (i == locatie.getNr_randuri() - 2 || i == locatie.getNr_randuri() - 1)
					{
						locuri_ocupate[i][j].setZona(tipZona::VIP);
					}
					else
					{
						locuri_ocupate[i][j].setZona(tipZona::Normal);
					}
				}
			}
		}
		//TEATRU--------
		if (locatie.getTipLocatie() == tipLocatiee::Teatru)
		{
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					if (i == locatie.getNr_randuri() - 2 || i == locatie.getNr_randuri() - 1)
					{
						locuri_ocupate[i][j].setZona(tipZona::Categoria2);
					}
					else
					{
						locuri_ocupate[i][j].setZona(tipZona::Categoria1);
					}
					if (j == 0 || j == locatie.getNr_locuri_rand() - 1)
					{
						locuri_ocupate[i][j].setZona(tipZona::Loja);
					}
				}
			}
		}

		//FOTBAL--------
		if (locatie.getTipLocatie() == tipLocatiee::Fotbal)
		{
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					locuri_ocupate[i][j].setZona(tipZona::Peluza);
					if (j == 0 || j == 1 || j == 2)
					{
						locuri_ocupate[i][j].setZona(tipZona::Tribuna1);
					}
					if (j == locatie.getNr_locuri_rand() - 3 || j == locatie.getNr_locuri_rand() - 2 || j == locatie.getNr_locuri_rand() - 1)
					{
						locuri_ocupate[i][j].setZona(tipZona::Tribuna2);
					}
				}
			}
		}
	}

	//Constructor de copiere------
	Eveniment(const Eveniment& E)
	{
		adresa = E.adresa;
		nume_eveniment = E.nume_eveniment;
		data = E.data;
		ora = E.ora;
		locatie = E.locatie;
		locuri_ocupate = E.locuri_ocupate;
	}

	//Metoda Sold out
	void Sold(Loc** locuri_ocupate)
	{
		int nr = 1;
		for (int i = 0; i < locatie.getNr_randuri(); i++)
		{
			for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
			{
				if (locuri_ocupate[i][j].getOcupat() == 0)
					nr = 0;
			}
		}
		if (nr == 1)
			cout << "Sold out!";
		else
		{
			cout << "Biletele disponibile sunt:";
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				nr = 0;
				cout << "Randul " << i << ": ";
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					if (locuri_ocupate[i][j].getOcupat() == 0)
					{
						cout << j << " ";
						nr++;
					}
				}
				if (nr == 0)
					cout << " Nu mai sunt bilete disponibile pe acest rand!";
			}
		}
	}

	//Metoda Zone Ocupate
	void ZoneOcupate(Locatie locatie, Loc** locuri_ocupate)
	{
		int nr1, nr2, nr3;
		//FILM---------
		if (locatie.getTipLocatie() == tipLocatiee::Film)
		{
			nr1 = 0;
			nr2 = 0;
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					if (locuri_ocupate[i][j].getZona() == VIP && locuri_ocupate[i][j].getOcupat() == 0)
						nr1 = 1;
					if (locuri_ocupate[i][j].getZona() == Normal && locuri_ocupate[i][j].getOcupat() == 0)
						nr2 = 1;
				}
			}
			if (nr1 == 0)
				cout << "Zona VIP este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile in zona VIP";

			if (nr2 == 0)
				cout << "Zona Normal este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile in zona Normal";
		}
		//TEATRU--------
		if (locatie.getTipLocatie() == tipLocatiee::Teatru)
		{
			nr1 = 0;
			nr2 = 0;
			nr3 = 0;
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
					{
						if (locuri_ocupate[i][j].getZona() == Categoria1 && locuri_ocupate[i][j].getOcupat() == 0)
							nr1 = 1;
						if (locuri_ocupate[i][j].getZona() == Categoria2 && locuri_ocupate[i][j].getOcupat() == 0)
							nr2 = 1;
						if (locuri_ocupate[i][j].getZona() == Loja && locuri_ocupate[i][j].getOcupat() == 0)
							nr3 = 1;
					}
				}
			}
			if (nr1 == 0)
				cout << "Zona Categoria 1 este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Categoria 1";

			if (nr2 == 0)
				cout << "Zona Categoria 2 este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Categoria 2";

			if (nr3 == 0)
				cout << "Zona Loja este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Loja";
		}

		//FOTBAL--------
		if (locatie.getTipLocatie() == tipLocatiee::Fotbal)
		{
			nr1 = 0;
			nr2 = 0;
			nr3 = 0;
			for (int i = 0; i < locatie.getNr_randuri(); i++)
			{
				for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
				{
					for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
					{
						if (locuri_ocupate[i][j].getZona() == Tribuna1 && locuri_ocupate[i][j].getOcupat() == 0)
							nr1 = 1;
						if (locuri_ocupate[i][j].getZona() == Tribuna2 && locuri_ocupate[i][j].getOcupat() == 0)
							nr2 = 1;
						if (locuri_ocupate[i][j].getZona() == Peluza && locuri_ocupate[i][j].getOcupat() == 0)
							nr3 = 1;
					}
				}
			}
			if (nr1 == 0)
				cout << "Zona Tribuna 1 este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Tribuna 1";

			if (nr2 == 0)
				cout << "Zona Tribuna 2 este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Tribuna 2";

			if (nr3 == 0)
				cout << "Zona Peluza este indisponibila.";
			else
				cout << "Mai sunt bilete disponibile la Peluza";
		}
	}


	//adresa----------------
	char* getAdresa()
	{
		if (adresa != nullptr)
		{
			char* adr = new char[strlen(adresa) + 1];
			for (int i = 0; i < strlen(adresa) + 1; i++)
				adr[i] = adresa[i];
			return adr;
		}
		return nullptr;
	}

	void setAdresa(const char* a)
	{
		if (a != nullptr)
			delete[] adresa;
		adresa = new char[strlen(a) + 1];
		for (int i = 0; i < strlen(a) + 1; i++)
			adresa[i] = a[i];
	}

	//nume_eveniment---------
	char* getNume_eveniment()
	{
		if (nume_eveniment != nullptr)
		{
			char* n_ev = new char[strlen(nume_eveniment) + 1];
			for (int i = 0; i < strlen(nume_eveniment) + 1; i++)
				n_ev[i] = nume_eveniment[i];
			return n_ev;
		}
		return nullptr;
	}

	void setNume_eveniment(const char* ev)
	{
		if (nume_eveniment != nullptr)
			delete[] nume_eveniment;
		nume_eveniment = new char[strlen(ev) + 1];
		for (int i = 0; i < strlen(ev) + 1; i++)
			nume_eveniment[i] = ev[i];
	}

	//data--------------------
	string getData()
	{
		return data;
	}

	void setData(string data)
	{
		Eveniment::data = data;
	}

	//ora----------------------
	string getOra()
	{
		return ora;
	}

	void setOra(string ora)
	{
		Eveniment::ora = ora;
	}


	//locatie------------------
	Locatie getLocatie()
	{
		return locatie;
	}

	void setLocatie(Locatie l)
	{
		locatie = l;
	}

	//agentie------------------
	static string getAgentie()
	{
		return agentie;
	}

	static void setAgentie(string agentie)
	{
		Eveniment::agentie = agentie;
	}

	Eveniment& operator=(const Eveniment& E)
	{
		if (this->adresa)
		{
			delete[] this->adresa;
		}
		this->adresa = new char[strlen(E.adresa) + 1];
		strcpy_s(this->adresa, strlen(E.adresa) + 1, E.adresa);

		if (this->nume_eveniment)
		{
			delete[] this->nume_eveniment;
		}
		this->nume_eveniment = new char[strlen(E.nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(E.nume_eveniment) + 1, E.nume_eveniment);

		this->data = E.data;
		this->ora = E.ora;

		this->locatie = E.locatie;

		if (this->locuri_ocupate)
		{
			for (int i = 0; i < this->locatie.getNr_randuri() - 1; i++)
			{
				delete[] locuri_ocupate[i];
			}
			delete[] locuri_ocupate;

		}
		Loc** locuri_ocupate = new Loc * [locatie.getNr_randuri() * locatie.getNr_locuri_rand()];
		for (int i = 0; i < locatie.getNr_randuri(); i++)
		{
			for (int j = 0; j < locatie.getNr_locuri_rand(); j++)
			{
				locuri_ocupate[i][j] = E.locuri_ocupate[i][j];
			}
		}
	}

	~Eveniment()
	{
		if (adresa != nullptr)
			delete[] adresa;

		if (nume_eveniment != nullptr)
			delete[] nume_eveniment;

		if (locuri_ocupate != nullptr)
			delete[] locuri_ocupate;
	}

	//Supraincarcare !
	char* operator!()
	{
		return adresa;
	}

	//Supraincarcare cast la int explicit
	explicit operator string()
	{
		return data;
	}


	friend istream& operator>>(istream& in, Eveniment& E)
	{
		cout << "Adresa este: ";
		char buffer[100];
		in >> buffer;
		if (E.adresa != NULL)
			delete E.adresa;
		E.adresa = new char[strlen(buffer) + 1];
		strcpy_s(E.adresa, strlen(buffer) + 1, buffer);

		cout << "Numele evenimentului este: ";
		char buffer1[100];
		in >> buffer1;
		if (E.nume_eveniment != NULL)
			delete E.nume_eveniment;
		E.nume_eveniment = new char[strlen(buffer1) + 1];
		strcpy_s(E.nume_eveniment, strlen(buffer1) + 1, buffer1);

		cout << "Data este: ";
		in >> E.data;

		cout << "Ora este: ";
		in >> E.ora;

		cout << "Locatia este: ";
		in >> E.locatie;

		cout << "Distribuirea locurilor: ";
		for (int i = 0; i < E.locatie.getNr_randuri(); i++)
		{
			for (int j = 0; j < E.locatie.getNr_locuri_rand(); j++)
			{
				in >> E.locuri_ocupate[i][j];
			}
		}

		return in;
	}

};

ostream& operator<<(ostream& out, Eveniment E)
{
	out << "Adresa: " << E.getAdresa() << endl;
	out << "Numele evenimentului: " << E.getNume_eveniment() << endl;
	out << "Data: " << E.getData() << endl;
	out << "Ora: " << E.getOra() << endl;
	out << "Locatie: " << E.getLocatie() << endl;
	out << "Agentie: " << E.getAgentie() << endl;
	return out;
}

string Eveniment::agentie = "iabilet.ro";