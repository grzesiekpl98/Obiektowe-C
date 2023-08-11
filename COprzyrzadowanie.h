#ifndef COPRZYRZADOWANIE_H
#define COPRZYRZADOWANIE_H
#include <string>
#include <iostream>

using namespace std;

class COprz
{
	public:
		COprz();
		~COprz();
		void dodaj_nazwa_oprz(string);
		void dodaj_ilosc_oprz(int);
		int wyswietl_liczba_oprz();
		string wyswietl_nazwa_oprz();
	private:
		string nazwa_oprz;
		int liczba_oprz;
};

#endif

