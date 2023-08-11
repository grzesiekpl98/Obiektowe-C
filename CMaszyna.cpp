#include "CMaszyna.h"
#include <iostream>
using namespace std;

CMaszyna :: CMaszyna ()
{
};

CMaszyna :: ~CMaszyna()
{
	
};

string CMaszyna :: wyswietl_nazwa_maszyna()
{
	return (nazwa_maszyna);
}
int CMaszyna :: wyswietl_liczba_maszyna()
{
	return (liczba_maszyna);
}
void CMaszyna :: dodaj_nazwa_maszyna(string m)
{
	nazwa_maszyna=m;
}
void CMaszyna :: dodaj_ilosc_maszyna(int n)
{
	liczba_maszyna=n;
}

