#include <iostream>
#include "CZaklad.h"
using namespace std;

CZaklad::CZaklad()
{
	licznik_zaklad = 0;
	licznik_oprz = 0;
	licznik_maszyna = 0;
}
CZaklad::~CZaklad()
{
}
void CZaklad::dodaj_nazwa_zaklad(string m)
{
	nazwa_zaklad = m;
}
string CZaklad::wyswietl_nazwa_zaklad()
{
	return(nazwa_zaklad);
}
int CZaklad::wyswietl_numer_zaklad()
{
	return(licznik_zaklad);
}
void CZaklad::dodaj_maszyna(int n, string m) 
{
	CMaszyna *w = new CMaszyna;  //UTWORZENIE WSKAZNIKA W DO OBIEKTU TYPU MASZYNA, ZA POMOCA NEW TWORZYMY OBIEKT DYNAMICZNY TYPU MASZYNA, PODSTAWIENIE WSKAZNIKA DO ADRESU UTWORZONEGO OBIEKTU, KTORY JEST ZWRACANY PRZEZ OPERATOR NEW DO ZMIENNEJ WSKAZNIKOWEJ MASZYNA
	
	w -> dodaj_ilosc_maszyna(n);  
	w -> dodaj_nazwa_maszyna(m);
	
	tab_maszyna[licznik_maszyna]=w;
    licznik_maszyna++;
}
void CZaklad::kasuj_maszyna(int w)
{
	delete tab_maszyna[w];
	for (int j = w; licznik_maszyna-1>j; j++)
	{
		tab_maszyna[j] = tab_maszyna[j+1];
	}
	licznik_maszyna--;
}
int CZaklad::wyswietl_ilosc_maszyna(int n)
{
	int ilosc_maszyna;
	ilosc_maszyna=tab_maszyna[n]->wyswietl_liczba_maszyna();
	return(ilosc_maszyna);
}
string CZaklad::wyswietl_nazwa_maszyna(int n)
{
	string nazwa_maszyna;
	nazwa_maszyna=tab_maszyna[n]->wyswietl_nazwa_maszyna();
	return(nazwa_maszyna);
}
int CZaklad::pobierz_licznik_maszyna()
{
	return(licznik_maszyna);
}
void CZaklad::dodaj_oprz(int n, string m)
{
	COprz *w2 = new COprz;
	
	w2 -> dodaj_ilosc_oprz(n);
	w2 -> dodaj_nazwa_oprz(m);
	
	tab_oprz[licznik_oprz]=w2;
    licznik_oprz++;
}
void CZaklad::kasuj_oprz(int z)
{
	delete tab_oprz[z];
	for (int n = z; licznik_oprz - 1>n; n++)
	{
		tab_oprz[n] = tab_oprz[n + 1];
	}
	licznik_oprz--;
}
int CZaklad::wyswietl_ilosc_oprz(int n)
{
	int ilosc_oprz;
	ilosc_oprz=tab_oprz[n]->wyswietl_liczba_oprz();
	return(ilosc_oprz);
}
string CZaklad::wyswietl_nazwa_oprz(int n)
{
	string nazwa_oprz;
	nazwa_oprz=tab_oprz[n]->wyswietl_nazwa_oprz();
	return(nazwa_oprz);
}
int CZaklad::pobierz_licznik_oprz()
{
	return(licznik_oprz);
}
void CZaklad::zmien_ilosc_maszyna(int n, int j)
{
tab_maszyna[n]->dodaj_ilosc_maszyna(j);
}

void CZaklad::zmien_ilosc_oprz(int n, int j)
{
tab_oprz[n]->dodaj_ilosc_oprz(j);
}


