#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include "CZaklad.h"
#include "CMaszyna.h"
#include "COprzyrzadowanie.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

CZaklad*tab_zaklad[100]; //tworzymy tablice wskaznikow
int licznik_zaklad = 0;	//nadajemy wartosc poczatkowa

int main() 
{   
	int opcja1, opcja2, opcja3; //zmienne uzywane w case
	int liczba_maszyna, liczba_oprz, ile_maszyna, ile_oprz; 
	
	string nazwa, nazwa_maszyna, nazwa_oprz;
	
	cout<<"Program pozwalajacy na wpisywanie i wyswietlanie: Zaklad, Maszyna, Oprzyrzadowanie"<<endl<<"Wykonali: Grzegorz Skonieczny oraz Anna Tomala"<<endl;
	do{
		cout<<" _______________________"<<endl;
		cout<<"|MENU:                  |"<<endl;
		cout<<"|1. Dodaj Zaklad        |"<<endl;
		cout<<"|2. Wyswietl Zaklad     |"<<endl;
		cout<<"|3. Edytuj Zaklad       |"<<endl;
		cout<<"|4. Kasuj Zaklad        |"<<endl;
		cout<<"|5. Opusc program       |"<<endl;
		cout<<"|_______________________|"<<endl;
		cout<<"Wybierz(nr): ";
		cin>>opcja1;
		
		switch (opcja1) 
		{
		case 1:
			{ 
				cout<<"|Wpisz nazwe Zakladu: ";
				cin>>nazwa;
				tab_zaklad[licznik_zaklad] = new CZaklad(); 
				tab_zaklad[licznik_zaklad] -> dodaj_nazwa_zaklad(nazwa);
					
					cout<<"|Ile rodzajow maszyn ma Zaklad "<<nazwa<<"?: ";
					cin>>ile_maszyna;
					
					for (int n = 0; n<ile_maszyna; n++)
					{
					cout<<"|Podaj nazwe maszyny: ";
					cin>>nazwa_maszyna;
					cout<<"|Podaj ilosc maszyn o nazwie "<<nazwa_maszyna<<": ";
					cin>>liczba_maszyna;
					
					tab_zaklad[licznik_zaklad]->dodaj_maszyna(liczba_maszyna, nazwa_maszyna);
					}
					cout<<"|Ile rodzajow oprzyrzadowania ma Zaklad "<<nazwa<<"?: ";
					cin>>ile_oprz;
					
					for (int n = 0; n<ile_oprz; n++)
					{
					cout<<"|Podaj nazwe oprzyrzadowania: ";
					cin>>nazwa_oprz;
					cout<<"|Podaj ilosc oprzyrzadowania o nazwie "<<nazwa_oprz<<": ";
					cin>>liczba_oprz;
					
					tab_zaklad[licznik_zaklad]->dodaj_oprz(liczba_oprz, nazwa_oprz);
					}
					cout<<"|Stworzono nowy Zaklad o nazwie "<<nazwa<<".|"<<endl;
					
				licznik_zaklad++;
				break;
			}
		case 2:
			{
				cout<<" ________________________________________________"<<endl;
				cout<<"|1. Wyswietl wszystkie Zaklady                   |"<<endl;
				cout<<"|2. Podaj numer Zakladu, ktory chcesz wyswietlic |"<<endl;
				cout<<"|[Inny]. Powrot do menu glownego                 |"<<endl;
				cout<<"|________________________________________________|"<<endl;
				cout<<"Wybierz(nr): ";
				cin>>opcja2;
				
				switch(opcja2)
				{
				case 1:
					{
						cout<<"|Twoje Zaklady: "<<endl;
						
						for(int n = 0; n<licznik_zaklad; n++)
						{
							cout<<" ____________________________"<<endl;
							cout<<"|"<<n<<". Zaklad o nazwie: "<< tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
								cout<<"|Maszyny: "<<endl;
								int h;
								h = tab_zaklad[n]->pobierz_licznik_maszyna();
								if (h == 0)
									{
										cout<<"|-Brak"<<endl;
									}
									for(int j=0; j<h; j++)
									{
										cout<<"|"<<j<<"."<<tab_zaklad[n]->wyswietl_nazwa_maszyna(j)<<" - "<<tab_zaklad[n]->wyswietl_ilosc_maszyna(j)<<endl;
									}
								cout<<"|Oprzyrzadowanie: "<<endl;
								
								int s;
								s = tab_zaklad[n]->pobierz_licznik_oprz();
								
								if (s == 0)
									{
										cout<<"|-Brak"<<endl;
									}
									
									for(int j=0; j<s; j++)
									{
										cout<<"|"<<j<<"."<<tab_zaklad[n]->wyswietl_nazwa_oprz(j)<<" - "<<tab_zaklad[n]->wyswietl_ilosc_oprz(j)<<endl;
									}		
						}
						break;
					}
				case 2:
					{
				  
						for(int n=0; n<licznik_zaklad; n++)
						{	
							cout<<"|"<<n<<". "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						cout<<"|Podaj numer Zaklad, ktory chcesz wyswietlic: ";
						int p;
						cin>>p;
						
						cout<<" ____________________________"<<endl;
						cout<<"|"<<p<<": "<<tab_zaklad[p]->wyswietl_nazwa_zaklad()<<endl;
						cout<<"|Maszyna: "<<endl;
						
						int h;
						h = tab_zaklad[p]->pobierz_licznik_maszyna();
						
						if (h == 0)
						{
							cout<<"|-Brak"<<endl;
						}
						
						for(int j=0; j<h;j++)
						{
							cout<<"|"<<j<<". "<<tab_zaklad[p]->wyswietl_nazwa_maszyna(j)<<" - "<<tab_zaklad[p]->wyswietl_ilosc_maszyna(j)<<endl;
						}
						
						cout<<"|Oprzyrzadowanie: "<<endl;
						int s;
						s = tab_zaklad[p]->pobierz_licznik_oprz();
						
						if (s == 0)
						{
							cout<<"|-Brak"<<endl;
						}
						
						for(int j=0; j<s; j++)
						{
							cout<<"|"<<j<<". "<<tab_zaklad[p]->wyswietl_nazwa_oprz(j)<<" - "<<tab_zaklad[p]->wyswietl_ilosc_oprz(j)<<endl;	
						}
						cout<<endl;
					
						break;
					}
					default:
					
					break;	
				}
					
			break;		
			}
		
		case 3:
			{
				cout<<" ___________________________________"<<endl;
				cout<<"|1. Zmien nazwe Zakladu             |"<<endl;
				cout<<"|2. Zmien ilosc maszyn              |"<<endl;
				cout<<"|3. Zmien ilosc oprzyrzadowania     |"<<endl;
				cout<<"|4. Usun maszyne z zakladu          |"<<endl;
				cout<<"|5. Usun oprzyrzadowanie z zakladu  |"<<endl;
				cout<<"|6. Dodaj maszyne do zakladu        |"<<endl;
				cout<<"|7. Dodaj oprzyrzadowanie do zakladu|"<<endl;
				cout<<"|[Inny]. Powrot do menu glownego    |"<<endl;         	
				cout<<"|___________________________________|"<<endl;   
				cout<<"Wybierz(nr): ";
				cin>>opcja3;
				
				switch(opcja3)
				{
				case 1:
					{
						for (int n= 0; n<licznik_zaklad; n++)  
						{
							cout<<"|"<<n<<" - "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;                            
						}
						
						cout<<"|Podaj numer Zakladu, w ktorym chcesz zmienic nazwe: ";
						int u;	
						cin>>u;
						
						cout<<"|Aktualna nazwa to: "<<tab_zaklad[u]->wyswietl_nazwa_zaklad()<<endl;
						cout<<"|Podaj nowa nazwe: ";
						cin>>nazwa;
						
						tab_zaklad[u]->dodaj_nazwa_zaklad(nazwa);
						
						break;
					}
				
				case 2:
					{
						for (int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<" - "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu, ktory chcesz edytowac: ";
						int o;
						cin>>o;
					
						int h;
						h = tab_zaklad[o]->pobierz_licznik_maszyna();
						
						for (int n=0; n<h; n++)
						{
							cout<<"|"<<n<<": "<<tab_zaklad[o]->wyswietl_nazwa_maszyna(n)<<" - "<<tab_zaklad[o]->wyswietl_ilosc_maszyna(n)<<endl;
						}
						cout<<"|Podaj numer maszyny, ktorej chcesz zmienic ilosc: ";
						int v;     
						cin>>v;
					
						cout<<"|Podaj nowa ilosc maszyn: ";
						cin>>liczba_maszyna;
						tab_zaklad[o]->zmien_ilosc_maszyna(v, liczba_maszyna);
					break;
					}
				case 3:
					{
						for (int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<" - "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu, ktory chcesz edytowac: ";
						int q;
						cin>>q;
					
						int s;
						s = tab_zaklad[q]->pobierz_licznik_oprz();
						
						for (int n=0; n<s; n++)
						{
							cout<<"|"<<n<<": "<<tab_zaklad[q]->wyswietl_nazwa_oprz(n)<<" - "<<tab_zaklad[q]->wyswietl_ilosc_oprz(n)<<endl;
						}
						cout<<"|Podaj numer oprzyrzadowanie, ktorej chcesz zmienic ilosc: ";
						int e;
						cin>>e;
						
						cout<<"|Podaj nowa ilosc oprzyrzadowanie: ";
						cin>>liczba_oprz;
						
						tab_zaklad[q]->zmien_ilosc_oprz(e, liczba_oprz);
						break;
					}
				case 4:
					{
						for (int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<". "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu z ktorego chcesz usunac maszyne: ";
						int s;
						cin>>s;
						
             			for (int j; j<ile_maszyna; j++)
						{
							cout<<"|"<<j<<": "<<tab_zaklad[s]->wyswietl_nazwa_maszyna(j)<<" - "<<tab_zaklad[s]->wyswietl_ilosc_maszyna(j)<<endl;
						}
						cout<<"|Podaj numer maszyny, ktora chcesz usunac: ";
              			int f;
						cin>>f;
              			
						int h;
						h = tab_zaklad[s]->pobierz_licznik_oprz();
              		
              			tab_zaklad[s]->kasuj_maszyna(f);
              		
              			cout<<"|Pomyslnie usunieto wybrana maszyne"<<endl;
						
						break;
					}
				case 5:
					{
						for(int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<" - "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu z ktorego chcesz usunac oprzyrzadowanie: ";
						int t;
						cin>>t;
						
						for (int j=0; j<ile_oprz; j++)
						{
							cout<<"|"<<j<<": "<<tab_zaklad[t]->wyswietl_nazwa_oprz(j)<<" - "<<tab_zaklad[t]->wyswietl_ilosc_oprz(j)<<endl;
						}
						
						cout<<"|Podaj numer oprzyrzadowania, ktore chcesz usunac: ";
              			int y;
						cin>>y;
						
						int s;
						s = tab_zaklad[t]->pobierz_licznik_oprz();
              	
              			tab_zaklad[t]->kasuj_oprz(y);
              			
              			cout<<"|Pomyslnie usunieto wybrane oprzyrzadowanie"<<endl;
              			
						break;
              		}
				case 6:
					{
						for (int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<". "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu do ktorego chcesz dodac maszyne: ";
						int s;
						cin>>s;
						
						cout<<"|Podaj nazwe tego maszyna: ";
						string h;
						cin>>h;
						
						cout<<"|Podaj ilosc tego maszyna: ";
						int g;
						cin>>g;
						
						tab_zaklad[s]->dodaj_maszyna(g, h);
						
						break;
					}		
				case 7:
					{
						for (int n=0; n<licznik_zaklad; n++)
						{
							cout<<"|"<<n<<". "<<"Zaklad: "<<tab_zaklad[n]->wyswietl_nazwa_zaklad()<<endl;
						}
						
						cout<<"|Podaj numer Zakladu do ktorego chcesz dodac oprzyrzadowanie: ";
						int s;
						cin>>s;
						
						cout<<"|Podaj nazwe tego oprzyrzadowania: ";
						string h;
						cin>>h;
						
						cout<<"|Podaj ilosc tego oprzyrzadowania: ";
						int g;
						cin>>g;
						
						tab_zaklad[s]->dodaj_oprz(g, h);
						
						break;
					}		
					default:
					break;	
				}
					
			break;		
			}
		case 4: 
			{
                for (int n=0; n<licznik_zaklad; n++)
				{
       	            cout<<"|"<<n<<": "<<tab_zaklad[n]->wyswietl_nazwa_zaklad();
                    cout<<endl;
                }
                cout<<"|Podaj numer Zakladu, ktory chcesz usunac: ";
              	int del;
				cin>>del;
				
                
                
				int s;
				s = tab_zaklad[del]->pobierz_licznik_oprz();
                
				for (int y = s; y < 0; y--)
                {
                	tab_zaklad[del]->kasuj_oprz(y);
            	}
            	
				int h;
				h = tab_zaklad[del]->pobierz_licznik_maszyna();
            	
				for (int f = h; f < 0; f--)
            	{
            		tab_zaklad[del]->kasuj_maszyna(f);
				}
				delete tab_zaklad[del];
				for (int n = del; n<licznik_zaklad-1; n++)
                {
                    tab_zaklad[n]=tab_zaklad[n+1];
                }
                licznik_zaklad--;		
				
				cout<<"|Zaklad numer "<<del<<" zostal pomyslnie usuniety|"<<endl;
				
				break;
			}
		case 5:
			{
				cout<<"|Do widzenia!!|"<<endl;
				
				break;
			}
		default:
			cout<<"Ups! Cos poszlo nie tak... Zacznijmy od nowa"<<endl;
			
			break;
						
		}
	 
	}
while(opcja1!=5);
	
return 0;
}

