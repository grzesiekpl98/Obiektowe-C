#include "COprzyrzadowanie.h"
#include <string>
#include <iostream>

using namespace std;

COprz :: COprz ()
{
};

COprz :: ~COprz()
{
	
};

string COprz :: wyswietl_nazwa_oprz()
{
	return (nazwa_oprz);
}
int COprz :: wyswietl_liczba_oprz()
{
	return (liczba_oprz);
}
void COprz :: dodaj_nazwa_oprz(string m)
{
	nazwa_oprz=m;
}
void COprz :: dodaj_ilosc_oprz(int n)
{
	liczba_oprz=n;
}

