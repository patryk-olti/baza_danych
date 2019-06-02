#include <cstdlib>
#include <iostream>
#include "rekord.h"
#include "tabela.h"
#include "functions.h"

using namespace std;

Rekord::Rekord()
{
	liczba_kolumn = 0;
	ilosc_int = 0;
	ilosc_string = 0;	
}

Rekord::Rekord(const Rekord& r) : 
	liczba_kolumn(r.liczba_kolumn),
	typy_kolumn(r.typy_kolumn),  
	ilosc_string(r.ilosc_string),
	ilosc_int(r.ilosc_int)
{
	if(r.liczba_kolumn > 0)
	{
		string *kt = new string[r.ilosc_string];
		int *kl = new int[r.ilosc_int];
		int *tk = new int[r.liczba_kolumn];


		for(int i=0; i<r.liczba_kolumn; i++)
		{
			tk[i] = r.typy_kolumn[i];
		}
	
		for(int i=0; i<r.ilosc_string; i++)
		{
			kt[i] = r.kolumny_tekstowe[i];
		}
	
		for(int i=0; i<r.ilosc_int; i++)
		{
			kl[i] = r.kolumny_liczbowe[i];
		}

		typy_kolumn = tk;
		kolumny_tekstowe = kt;
		kolumny_liczbowe = kl;
	}
}

Rekord::Rekord(int lk, int *tk, int ii, int is)
{
	liczba_kolumn = lk;
	int *typy_kolumn = new int[liczba_kolumn];
	*typy_kolumn = *tk;
	ilosc_int = ii;
	ilosc_string = is;
	
}

Rekord::~Rekord()
{
	//delete []typy_kolumn_rekord;
	delete []chwilowa_kolumna_liczbowa;
	delete []chwilowa_kolumna_tekstowa;
}


void Rekord::wypelnij()
{
	cout<<liczba_kolumn;
	kontynuuj();

	int wyjscie=0, a=0, b=0;
	char znak;

	chwilowa_kolumna_liczbowa = new int [ilosc_int];
	chwilowa_kolumna_tekstowa = new string [ilosc_string];
	while(wyjscie==0)
	{
		cout<<"Dodac rekord? [T|N]";
	        cin>>znak;
	        if(znak=='t' || znak=='T')
		{
        		for(int i=0; i<liczba_kolumn; i++)
            		{
                		cout<<"Uzupelniasz wlasnie kolumne "<<i+1;
                		if(typy_kolumn[i]==0)
                		{
                    			cout<<" typ kolumny [integer] :";
                    			cin>>chwilowa_kolumna_liczbowa[a];
                    			a++;
                		}
                		else
                		{
                    			cout<<" typ kolumny [string] :";
                    			cin>>chwilowa_kolumna_tekstowa[b];
                    			b++;               
                		}
            		} 
		 	wyjscie=1;  
        	}
        	else
        	{
            		if(znak=='n' || znak=='N')
            		{
                		cout<<"Koniec dodawania rekordow!";
				kontynuuj();                		
				exit(0);
            		}
            		else
            		{
                		cout<<"Blad wprowadzenia!";
            		}   
        	}
    	}
/*
	----------------------------
	int wyjscie=0, a=0, b=0;
	char znak;

	chwilowa_kolumna_liczbowa = new int[ilosc_int];
	chwilowa_kolumna_tekstowa = new string[ilosc_string];

	while(wyjscie==0)
	{
		cout<<"Dodac rekord? [T|N]";
	        cin>>znak;
	        if(znak=='t' || znak=='T')
		{
        		for(int i=0; i<liczba_kolumn; i++)
            		{
                		cout<<"Uzupelniasz wlasnie kolumne "<<nazwa_kolumny[i];
                		if(typy_kolumn[i]==0)
                		{
                    			cout<<" typ kolumny [integer] :";
                    			cin>>chwilowa_kolumna_liczbowa[a];
                    			a++;
                		}
                		else
                		{
                    			cout<<" typ kolumny [string] :";
                    			cin>>chwilowa_kolumna_tekstowa[b];
                    			b++;               
                		}
            		} 
		 	wyjscie=1;  
        	}
        	else
        	{
            		if(znak=='n' || znak=='N')
            		{
                		cout<<"Koniec dodawania rekordow!";
                		wyjscie=1;
            		}
            		else
            		{
                		cout<<"Blad wprowadzenia!";
            		}   
        	}
    	}	
*/
}
/*
void Rekord::wyswietl()
{
	int a=0, b=0;

	cout<<"Aktualny rekord w buforze to: "<<endl;
	
	for(int i=0; i<liczba_kolumn; i++)
	{
		if(typy_kolumn_rekord[i]==0)
		{	
			cout<<chwilowa_kolumna_liczbowa[a];
			a++;
		}
		else
		{
			cout<<chwilowa_kolumna_tekstowa[b];
			b++;
		}
		cout<<"\t";
	}	
}
*/
void Rekord::setLiczba_Kolumn(int lk)
{
	liczba_kolumn = lk;
}


/*
void Rekord::dodaj_rekord(Tabela& t)
{

	int wyjscie=0, a=0, b=0;
	char znak;

	chwilowa_kolumna_liczbowa = new int[ilosc_int];
	chwilowa_kolumna_tekstowa = new string[ilosc_string];

	while(wyjscie==0)
	{
		cout<<"Dodac rekord? [T|N]";
	        cin>>znak;
	        if(znak=='t' || znak=='T')
		{
        		for(int i=0; i<liczba_kolumn; i++)
            		{
                		cout<<"Uzupelniasz wlasnie kolumne "<<nazwa_kolumny[i];
                		if(typy_kolumn[i]==0)
                		{
                    			cout<<" typ kolumny [integer] :";
                    			cin>>chwilowa_kolumna_liczbowa[a];
                    			a++;
                		}
                		else
                		{
                    			cout<<" typ kolumny [string] :";
                    			cin>>chwilowa_kolumna_tekstowa[b];
                    			b++;               
                		}
            		} 
		 	wyjscie=1;  
        	}
        	else
        	{
            		if(znak=='n' || znak=='N')
            		{
                		cout<<"Koniec dodawania rekordow!";
                		wyjscie=1;
            		}
            		else
            		{
                		cout<<"Blad wprowadzenia!";
            		}   
        	}
    	}	
}
*/