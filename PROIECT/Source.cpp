#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Loc.h"
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
using namespace std;


int main()
{
	Loc l1(4,17,0,Categoria1);
	cout << l1;
	Bilet b1;

	return 0;
}