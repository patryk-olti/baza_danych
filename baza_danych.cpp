#include <iostream>
#include "baza_danych.h"
#include "tabele.h"

using namespace std;

void Baza_Danych::utworz_tabele()
{
	string nazwa;       
	int typ, error=0;
	ilosc_int = 0;
	ilosc_string = 0;   

	cout<<"Podaj nazwe tabeli: ";
	cin>>nazwa_tabeli;
	cout<<"Podaj ilosc kolumn: ";
	cin>>liczba_kolumn;

	typy_kolumn = new int [liczba_kolumn];
	nazwa_kolumny = new string [liczba_kolumn];

	for(int i=0; i<liczba_kolumn; i++)
	{
	        error = 0;

	        cout<<"Podaj nazwe kolumny: ";
	        cin>>nazwa;
	        nazwa_kolumny[i] = nazwa;

	        while(error == 0)
		{
			cout<<"Podaj typ kolumny [ 0 - int | 1 - string ]: ";       
            		cin>>typ;
       
            		if(typ==0 || typ==1)        //mechanizm ochrony aby z klaw. zostala podana wart: 0 lub 1
            		{
                		if(typ == 0)
                		{
                			ilosc_int++;
                  			typy_kolumn[i] = typ;
                    			error = 1;
                		}               
                		else
                		{
                    			ilosc_string++;
                    			typy_kolumn[i] = typ;
                    			error = 1;               
                		}
            		}
            		else
            		{
                		cout<<"Blad, rzadana wartosc nie jest rowna zalozeniom!\n";
            		}
        	}
    	}
}