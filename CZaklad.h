#ifndef CZAKLAD_H
#define CZAKLAD_H
#include "CMaszyna.h"
#include "COprzyrzadowanie.h"
using namespace std;

class CZaklad
{
	private:
		int licznik_zaklad;
		int licznik_maszyna;
		int licznik_oprz;
		CMaszyna *tab_maszyna[100];
		COprz *tab_oprz[100];
		string nazwa_zaklad;
		
	public:
		CZaklad();
		~CZaklad();
		void dodaj_nazwa_zaklad(string);
		string wyswietl_nazwa_zaklad();
		int wyswietl_numer_zaklad();
		
		void dodaj_maszyna(int, string);
		string wyswietl_nazwa_maszyna(int);
		int wyswietl_ilosc_maszyna(int);
		//int ile_jest_maszyna(int);
		int pobierz_licznik_maszyna();
		void zmien_ilosc_maszyna(int, int);
		void kasuj_maszyna(int);
		
		void dodaj_oprz(int, string);
		string wyswietl_nazwa_oprz(int);
		int wyswietl_ilosc_oprz(int);
		//int ile_jest_oprz(int);
		int pobierz_licznik_oprz();
		void zmien_ilosc_oprz(int, int);
		void kasuj_oprz(int);
		
			
};

#endif

