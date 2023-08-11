#ifndef CMASZYNA_H
#define CMASZYNA_H
#include <string>
#include <iostream>

using namespace std;

class CMaszyna
{
	public:
		CMaszyna();
		~CMaszyna();
		void dodaj_ilosc_maszyna(int);
		void dodaj_nazwa_maszyna(string);
		int wyswietl_liczba_maszyna();
		string wyswietl_nazwa_maszyna();
		
	private:
		string nazwa_maszyna;
		int liczba_maszyna;
};

#endif

