#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "tabela.h"
#include "menu.h"
#include "functions.h"
#include "rekord.h"

using namespace std;

void Menu::wyswietl()
{
	Tabela t(0,0,"Brak");
	Rekord r;
	CellText c;	
	int wybor, koniec=0;

	system("clear");
	cout<<"Witaj w kreatorze budowania Bazy Danych!";
	kontynuuj();
   
	while(koniec==0)
	{
		cout<<"Kreator Bazy danych.\n\n1.\tWyswietl aktualna Tabele.\n2.\tUtworz Nowa Tabele.\n3.\tWczytaj tabele z pliku.\n4.\tZapisz aktualna tabele do pliku.\n5.\tDodaj rekord\n6.\tWyswietl aktualny rekord\n7.\tZapis aktualnego rekordu do tabeli\n8.\tWyzeruj plik .txt\n9.\tWyswietl rekord po komorkach.\n\n\n0.\tZakoncz Program.";
	        cin>>wybor;
       		switch(wybor)
       		{
            		case 1:
            		{
                		t.drukuj();
                		kontynuuj();
            		}
            		break;
            		case 2:   
			{
				t.utworz_tabele();
				kontynuuj();
			}
			break;
			case 3:   
			{       
				t.odczyt_z_pliku();
				kontynuuj();
			}
			break;
			case 4: 
			{
				t.zapis_do_pliku();
				kontynuuj();
			}
			break;
			case 5: 
			{	
				//r.dodaj_rekord(t);				
				t.dodaj_rekord();				
				kontynuuj();			
			}
			break;
			case 6:
			{
				//r.wyswietl();
				t.wyswietl_rekord();				
				kontynuuj();
			}
			break;
			case 7:
			{
				//r.wyswietl();
				t.zapis_rekordu();				
				kontynuuj();
			}
			break;

			case 8: 
			{
				cout<<"STILL NO WORKING"<<endl;
				//t.reset_pliku();
				kontynuuj();
			}
			break;   
		
			case 9:
			{
				//c.drukuj_bufor();
				t.drukuj_bufor();				
				kontynuuj();
			}
			break;

			case 0: 
			{
				exit(0);
			}
			break;  

			default: cout<<"Blad wyboru!";
        	}
	}   
}