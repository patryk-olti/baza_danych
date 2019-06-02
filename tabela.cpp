#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include "tabela.h"
#include "functions.h"
#include "rekord.h"

using namespace std;

/*
Tabela::Tabela()
{
	kolumny_liczbowe = new int [100];
	kolumny_tekstowe = new string [100];

	liczba_kolumn = 1;
	liczba_rekordow = 0;
	nazwa_tabeli = "Brak";
	ilosc_int = 0;
	ilosc_string = 0;
	liczba_rekordow = 0;

	//int tablica_typow[liczba_kolumn];
	//tablica_typow[0] = *typy_kolumn;

	for(int i=0; i<liczba_kolumn; i++)
	{
		//tablica_typow[i] = 0;
		kolumny_liczbowe[i] = 0;
		kolumny_tekstowe[i] = "brak";
	}
}*/

Tabela::Tabela()
{
	liczba_kolumn = liczba_kolumn;
	*typy_kolumn = *typy_kolumn;
}

Tabela::Tabela(int l_k, int l_r, string n_t)
{
	liczba_kolumn = l_k;
	liczba_rekordow = l_r;
	nazwa_tabeli = n_t;
	//kolumny_liczbowe = new int [100];
	//kolumny_tekstowe = new string [100];
	index_a = 0;
	index_b = 0;
}

Tabela::~Tabela()
{
	delete []typy_kolumn;
	delete []nazwa_kolumny;
	delete []kolumny_tekstowe;
	delete []kolumny_liczbowe;
	delete []chwilowa_kolumna_liczbowa;
	delete []chwilowa_kolumna_tekstowa;
}

void Tabela::drukuj()
{
    int a=0, b=0;
   
    cout<<"Nazwa Tabeli: "<<nazwa_tabeli<<endl;       
   
    for(int i=0; i<liczba_kolumn; i++)
    {
        cout<<nazwa_kolumny[i]<<"\t";
    }

    cout<<endl;

    for(int j=0; j<liczba_rekordow; j++)
    {
        for(int i=0; i<liczba_kolumn; i++)
        {   
            if(typy_kolumn[i] == 0)
            {           
                cout<<kolumny_liczbowe[a];
                a++;
            }
            else
            {
                cout<<kolumny_tekstowe[b];
                b++;
            }
            cout<<"\t";   
        }

        cout<<endl;
    }
}

void Tabela::dodaj_rekord()
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

void Tabela::zapis_rekordu()
{
	chwilowa_ilosc_tekstowa = 0;
	chwilowa_ilosc_liczbowa = 0;	

	char znak;
	int a=0, b=0, wyjscie=0;
	
	while(wyjscie==0)
	{
		cout<<"Zapisac rekord? [T|N]";
	        cin>>znak;
	        if(znak=='t' || znak=='T')
		{
			liczba_rekordow++;
        		for(int i=0; i<liczba_kolumn; i++)
            		{
                		if(typy_kolumn[i]==0)
                		{
                    			kolumny_liczbowe[index_a] = chwilowa_kolumna_liczbowa[a];
					chwilowa_ilosc_liczbowa++;
                    			a++;
					index_a++;                		
				}
                		else
                		{
                    			kolumny_tekstowe[index_b] = chwilowa_kolumna_tekstowa[b];
					chwilowa_ilosc_tekstowa++;
                    			b++;
					index_b++;               
                		}
            		} 
		 	wyjscie=1;  
        	}
        	else
        	{
            		if(znak=='n' || znak=='N')
            		{
                		cout<<"Nie zapisano rekordu!";
                		wyjscie=1;
            		}
            		else
            		{
                		cout<<"Blad wprowadzenia!";
            		}   
        	}
    	}	
}

void Tabela::utworz_tabele()
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
//Rekord r;
//r.setLiczba_Kolumn(liczba_kolumn);
//Rekord r(liczba_kolumn, *typy_kolumn, ilosc_int, ilosc_string);
}

void Tabela::wyswietl_rekord()
{
	int a=0, b=0;

	for(int i=0; i<liczba_kolumn; i++)
 	{
               	if(typy_kolumn[i]==0)
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

void Tabela::zapis_do_pliku()
{
	int a = 0;
	int b = 0;
	fstream plik;
	plik.open("Tabela.txt",ios::out);

	plik<<nazwa_tabeli<<endl;
	plik<<liczba_kolumn<<endl;
	plik<<liczba_rekordow<<endl;
	plik<<index_a<<endl;
	plik<<index_b<<endl;	

	for(int i=0; i<liczba_kolumn; i++)
	{
	        plik<<nazwa_kolumny[i]<<endl;
	}

	for(int i=0; i<liczba_kolumn; i++)
	{
	        plik<<typy_kolumn[i]<<endl;
	}
	
	for(int j=0; j<liczba_rekordow; j++)
	{
	        for(int i=0; i<liczba_kolumn; i++)
	        {   
		        if(typy_kolumn[i] == 0)
        		{           
                		plik<<kolumny_liczbowe[a]<<endl;
                		a++;
            		}
            		else
            		{
                		plik<<kolumny_tekstowe[b]<<endl;
                		b++;
            		}
        	}
    	}
	
	plik.close();
}

void Tabela::odczyt_z_pliku()
{
	kolumny_liczbowe = new int [100];
	kolumny_tekstowe = new string [100];

	fstream plik;
	plik.open("Tabela.txt",ios::in);
	
	if(plik.good()==false)
	{
		cout<<"Brak utworzonego pliku!";
		kontynuuj();
		exit(0);
	}

	int a = 0;
	int b = 0;
	int i = 0, x = 0;
	int typy = 0, typy_2 = 0;
	string linia;
	int nr_linii = 1;

	while(getline(plik,linia))
	{
		if(nr_linii == 1)
		{
			nazwa_tabeli = linia;
		}
		else
		{
			if(nr_linii == 2)
			{
				liczba_kolumn = atoi(linia.c_str());
				typy_kolumn = new int [liczba_kolumn];
   				nazwa_kolumny = new string [liczba_kolumn];
			}
			else
			{
				if(nr_linii == 3)
				{		
					liczba_rekordow = atoi(linia.c_str());
					typy = liczba_kolumn + 5;
					typy_2 = typy + liczba_kolumn;				
				}
				else
				{
					if(nr_linii == 4)
					{
						index_a = atoi(linia.c_str());
					}
					else
					{
						if(nr_linii == 5)
						{
							index_b = atoi(linia.c_str());
						}
						else
						{
							if(nr_linii <= typy && nr_linii > 5)
							{
								nazwa_kolumny[i] = linia;
								i++;
							}
							else
							{
								if(nr_linii <= typy_2)
								{
									typy_kolumn[x] = atoi(linia.c_str());
									x++;
									i = 0;
								}
								else
								{
									if(nr_linii > typy_2)
									{
										if(i == liczba_kolumn)
											i = i - liczba_kolumn;

										if(typy_kolumn[i] == 0)
										{
											kolumny_liczbowe[a] = atoi(linia.c_str());
											a++;
											i++;
										}
										else
										{
											kolumny_tekstowe[b] = linia;
											b++;
											i++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		nr_linii++;
	}
	plik.close();
}

int Tabela::getTypy_Kolumn(int i)
{
	return typy_kolumn[i];
}

int Tabela::getLiczba_Kolumn()
{
	return liczba_kolumn;
}	

void Tabela::drukuj_bufor()
{
	int a = 1;


	cout<<"Komorki tekstowe: "<<endl;
	for(int i=0; i<index_b ; i++)
	{
		cout<<"Komorka "<<a<<": "<<kolumny_tekstowe[i]<<endl;
		a++;	
	}

	cout<<endl<<"Komorki liczbowe: "<<endl;
	for(int i=0; i<index_a; i++)
	{
		cout<<"Komorka "<<a<<": "<<kolumny_liczbowe[i]<<endl;
		a++;
	}
}



void Tabela::reset_pliku()
{
	fstream plik;
	plik.open("Tabela.txt", ios::out);
	plik.close();
	
	delete []typy_kolumn;
	delete []nazwa_kolumny;
	delete []kolumny_tekstowe;
	delete []kolumny_liczbowe;
	delete []chwilowa_kolumna_liczbowa;
	delete []chwilowa_kolumna_tekstowa;

}