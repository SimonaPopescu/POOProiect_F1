#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Loc.h"
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
using namespace std;

int nr = 0;

void citireFisier()
{
	ifstream r;
	r.open("Data.txt", ios::in);
	int m, n;
	r >> m >> n;
}


//scriere in binar
void scriereBinar(string nume)
{
	ofstream o(nume, ios::out | ios::binary);
}

int main()
{
	ofstream h;
	h.open("matrice.txt", ios::out);

	ofstream f;
	f.open("dateIntroduse.txt", ios::out);

	cout << endl;
	cout << endl;
	Locatie Stadion1(200, 100, Fotbal), Stadion2(100, 50, Fotbal);
	Locatie Teatru1(3, 3, Teatru), Teatru2(15, 15, Teatru);
	Locatie Cinema1(9, 15, Film), Cinema2(12, 15, Film);
	Eveniment Piesa1("Bulevardul Nicolae Balcescu, nr 3", "Nebun din dragoste", "13 noiembrie 2023", "18:30", Teatru1);
	Eveniment Piesa2("Bulevardul Nicolae Balcescu, nr 3", "Exilul", "14 ianuarie 2023", "20:30", Teatru2);
	Eveniment FilmAvatar1("Mega Mall Bucuresti - Bulevardul Pierre de Coubertin 3-5", "Avatar 2", "22 ianuarie 2023", "11:00", Cinema1);
	Eveniment FilmAvatar2("Mega Mall Bucuresti - Bulevardul Pierre de Coubertin 3-5", "Avatar 2", "22 ianuarie 2023", "14:30", Cinema1);
	Eveniment Meci1("Arena Nationala, Bulevardul Pierre de Coubertin", "Real Madrid  - Barcelona", "23 ianuarie 2023", "17:30", Stadion1);
	Eveniment Meci2("Arena Nationala, Bulevardul Pierre de Coubertin", "Meci Otelul Galati - Dinamo", "25 februarie 2023", "18:00", Stadion2);
	Loc l1(1, 1, 0, Categoria1);
	Loc l2(1, 2, 0, Categoria1);
	Loc l3(1, 3, 0, Categoria1);
	Loc l4(2, 1, 0, Categoria2);
	Loc l5(2, 2, 0, Loja);
	Loc l6(2, 3, 0, Categoria2);
	Loc l7(3, 1, 0, Categoria2);
	Loc l8(3, 2, 0, Loja);
	Loc l9(3, 3, 0, Loja);
	Loc vObiecte[9];
	vObiecte[0] = l1;
	vObiecte[1] = l2;
	vObiecte[2] = l3;
	vObiecte[3] = l4;
	vObiecte[4] = l5;
	vObiecte[5] = l6;
	vObiecte[6] = l7;
	vObiecte[7] = l8;
	vObiecte[8] = l9;
	
	
	/*ofstream s;
	s.open("VectorObiecte.txt", ios::out);
	for (int i = 0; i < 9; i++)
	{
		s << vObiecte[i];
	}*/

	cout << endl;
	cout << endl;

	fstream w;
	w.open("Data.txt", ios::in | ios::out | ios::app);

	fstream s;
	s.open("VectorObiecte.txt", ios::in);


	//MENIU
	cout << "	 ---------------------------------------------" << endl;
	cout << "	|                                             |" << endl;
	cout << "	|                                             |" << endl;
	cout << "	|        Bine ati venit pe Iabilet.ro         |" << endl;
	cout << "	|                                             |" << endl;
	cout << "	|                                             |" << endl;
	cout << "	 ---------------------------------------------" << endl;
	cout << endl;
	cout << "          Apasati tasta Enter pentru a accesa meniul." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << endl;
	cout << endl;
	cout << "    Doresti sa citesti datele de la tastatura sau din fisier text?" << endl;
	cout << "    Introdu valoarea 1 pentru a introduce de la tastatura!" << endl;
	cout << "    Introdu valoarea 2 pentru a citi din fisier text!" << endl;
	cout << "    Introdu valoarea 3 pentru a parasi aplicatia!" << endl;
	int y;
	cout << "    " << endl;
	cin >> y;
	switch (y)
	{
	case 1:
	{
		cout << "    Ai ales sa introduci valorile de la tastatura!" << endl;
		system("pause");
		system("cls");
		cout << endl;
		cout << endl;
		cout << "    Categorii evenimente:" << endl;
		cout << "    1. Teatru" << endl;
		cout << "    2. Film" << endl;
		cout << "    3. Fotbal" << endl;
		cout << "    4. Iesire" << endl;
		cout << endl;
		cout << endl;
		cout << "    Alege categoria de eveniment prin introducerea numarului asignat: " << endl;
		int x;
		cout << "    ";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "    Ai ales categoria TEATRU" << endl;
			cout << endl;
			cout << "    Calendarul pieselor de teatru: " << endl;
			cout << "    1. Nebun din dragoste - 13 noiembrie 2023 , ora 18:30" << endl;
			cout << "    2. Exilul - 14 ianuarie , ora 20:30" << endl;
			cout << "    3. Cursa de soareci - 21 ianuarie, ora 19:00" << endl;

			cout << endl;
			cout << "    Alege piesa de teatru prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales piesa Nebun din dragoste" << endl;
				int a, b, c, d;
				Loc* locuri = new Loc[9];
				for (int i = 0; i < 9; i++)
				{
					locuri[i] = vObiecte[i];
				}

				cout << endl;
				cout << "    Introdu numarul randului:" << endl;
				cout << "    " << endl;
				int m;
				cin >> m;
				cout << endl;
				cout << "    Introdu numarul locului:" << endl;
				cout << "    " << endl;
				int n;
				cin >> n;
				cout << endl;
				w << m << " " << n << endl;

				for (int i = 0; i < 9; i++)
				{
					s >> a >> b >> c >> d;
					if (a == m && b == n)
					{
						locuri[i].ocupaLoc(locuri[i], m, n);
						locuri[i].setOcupat(1);
					}
				}
				s.close();
				ofstream p("VectorObiecte.txt", ios::out);
				for (int i = 0; i < 9; i++)
				{
					p << locuri[i];
				}

				cout << endl;
				cout << "    Distributia salii dupa rezervare: " << endl;
				cout << endl;
				for (int i = 0; i < 9; i++)
				{
					cout << locuri[i] << " ";
					if (i == 2 || i == 5 || i == 8)
						cout << endl;
				}

				nr++;

				break;
			}
			case 2:
			{
				cout << "    Ai ales piesa ,," << Piesa2.getNume_eveniment() << " '' ";
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}

			}
			break;
		}
		case 2:
		{
			cout << "    Ai ales categoria FILM" << endl;
			cout << endl;
			cout << "    Filmele disponibile sunt: " << endl;
			cout << "    1. Avatar 2" << endl;
			cout << "    2. Exilul - 14 ianuarie , ora 20:30" << endl;

			cout << endl;
			cout << "    Alege filmul prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales filmul ,,Avatar 2'' ";
				cout << endl;
				cout << "    Datele disponibile sunt: " << endl;
				cout << "    1. 22 ianuarie 2022" << endl;
				cout << endl;
				cout << "    Te rog selecteaza data pe care o doresti prin introducerea numarului asignat :" << endl;
				int a;
				cout << "    ";
				cin >> a;
				if (a == 1)
				{
					cout << "    Ai ales data de 22 ianuarie 2023" << endl;
					cout << endl;
					cout << "    Orele disponibile sunt: " << endl;
					cout << "    1. 11:00" << endl;
					cout << "    2. 14:30" << endl;
					cout << "    3. 19:30" << endl;
					cout << "    4. 23:00" << endl;
					cout << endl;
					cout << "    Te rog selecteaza ora pe care o doresti prin introducerea numarului asignat: " << endl;
					int b;
					cout << "    ";
					cin >> b;
					if (b == 1)
						cout << "    Ai ales ora " << FilmAvatar1.getOra();
					if (b == 2)
						cout << "    Ai ales ora " << FilmAvatar2.getOra();
				}
				break;
			}
			case 2:
			{
				cout << "    Ai ales filmul ,," << Piesa2.getNume_eveniment() << " '' ";
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}
			break;
			}
			break;
		}
		case 3:
		{
			cout << "    Ai ales categoria FOTBAL" << endl;
			cout << endl;
			cout << "    Meciurile disponibile sunt: " << endl;
			cout << "    1. Real Madrid - Barcelona, ora 19:00" << endl;
			cout << "    2. Otelul Galati - Dinamo, 14:00" << endl;

			cout << endl;
			cout << "    Alege meciul prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales meciul Real Madrid - Barcelona ";
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "    Ai ales meciul Otelul Galati - Dianmo " << endl;
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}
			break;
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			cout << "             Valoarea introdusa nu este potrivita." << endl;
			cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
		}
		break;
		}
	case 2:
	{
		cout << "    Ai ales sa citesti valorile din fisier text!" << endl;
		system("pause");
		system("cls");
		cout << endl;
		cout << endl;
		cout << "    Categorii evenimente:" << endl;
		cout << "    1. Teatru" << endl;
		cout << "    2. Film" << endl;
		cout << "    3. Fotbal" << endl;
		cout << "    4. Iesire" << endl;
		cout << endl;
		cout << endl;
		cout << "    Alege categoria de eveniment prin introducerea numarului asignat: " << endl;
		int x;
		cout << "    ";
		cin >> x;
		cout << endl;
		cout << endl;
		cout << "    Alege categoria de eveniment prin introducerea numarului asignat: " << endl;
		int q;
		cout << "    ";
		cin >> q;
		switch (q)
		{
		case 1:
		{
			cout << "    Ai ales categoria TEATRU" << endl;
			cout << endl;
			cout << "    Calendarul pieselor de teatru: " << endl;
			cout << "    1. Nebun din dragoste - 13 noiembrie 2023 , ora 18:30" << endl;
			cout << "    2. Exilul - 14 ianuarie , ora 20:30" << endl;
			cout << "    3. Cursa de soareci - 21 ianuarie, ora 19:00" << endl;

			cout << endl;
			cout << "    Alege piesa de teatru prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales piesa Nebun din dragoste" << endl;
				int a, b, c, d;
				Loc* locuri = new Loc[9];
				for (int i = 0; i < 9; i++)
				{
					locuri[i] = vObiecte[i];
				}

				
				break;
			}
			case 2:
			{
				cout << "    Ai ales piesa ,," << Piesa2.getNume_eveniment() << " '' ";
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}

			}
			break;
		}
		case 2:
		{
			cout << "    Ai ales categoria FILM" << endl;
			cout << endl;
			cout << "    Filmele disponibile sunt: " << endl;
			cout << "    1. Avatar 2" << endl;
			cout << "    2. Exilul - 14 ianuarie , ora 20:30" << endl;

			cout << endl;
			cout << "    Alege filmul prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales filmul ,,Avatar 2'' ";
				cout << endl;
				cout << "    Datele disponibile sunt: " << endl;
				cout << "    1. 22 ianuarie 2022" << endl;
				cout << endl;
				cout << "    Te rog selecteaza data pe care o doresti prin introducerea numarului asignat :" << endl;
				int a;
				cout << "    ";
				cin >> a;
				if (a == 1)
				{
					cout << "    Ai ales data de 22 ianuarie 2023" << endl;
					cout << endl;
					cout << "    Orele disponibile sunt: " << endl;
					cout << "    1. 11:00" << endl;
					cout << "    2. 14:30" << endl;
					cout << "    3. 19:30" << endl;
					cout << "    4. 23:00" << endl;
					cout << endl;
					cout << "    Te rog selecteaza ora pe care o doresti prin introducerea numarului asignat: " << endl;
					int b;
					cout << "    ";
					cin >> b;
					if (b == 1)
						cout << "    Ai ales ora " << FilmAvatar1.getOra();
					if (b == 2)
						cout << "    Ai ales ora " << FilmAvatar2.getOra();
				}
				break;
			}
			case 2:
			{
				cout << "    Ai ales filmul ,," << Piesa2.getNume_eveniment() << " '' ";
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}
			break;
			}
			break;
		}
		case 3:
		{
			cout << "    Ai ales categoria FOTBAL" << endl;
			cout << endl;
			cout << "    Meciurile disponibile sunt: " << endl;
			cout << "    1. Real Madrid - Barcelona, ora 19:00" << endl;
			cout << "    2. Otelul Galati - Dinamo, 14:00" << endl;

			cout << endl;
			cout << "    Alege meciul prin introducerea numarului asignat: " << endl;
			int z;
			cin >> z;
			switch (z)
			{
			case 1:
			{
				cout << "    Ai ales meciul Real Madrid - Barcelona ";
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "    Ai ales meciul Otelul Galati - Dianmo " << endl;
				break;
			}
			default:
			{
				cout << "             Valoarea introdusa nu este potrivita." << endl;
				cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
			}
			break;
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			cout << "             Valoarea introdusa nu este potrivita." << endl;
			cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
		}
		break;
		}
	}
	case 3:
	{
		return 0;
	}
	default:
	{
		cout << "             Valoarea introdusa nu este potrivita." << endl;
		cout << "   Te rog sa introduci o alta valoare dintre cele din meniu!" << endl;
	}
	}
	}
	
	return 0;

}
