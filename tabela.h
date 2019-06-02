#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "celltext.h"

using namespace std;

class Tabela
	: public CellText
{
	private:
	int liczba_kolumn;
	int liczba_rekordow;
	string nazwa_tabeli;
	int *typy_kolumn;
	string *nazwa_kolumny;

	int *kolumny_liczbowe;
	string *kolumny_tekstowe;
	int ilosc_int, ilosc_string;

	//int *chwilowa_kolumna_liczbowa;
	//string *chwilowa_kolumna_tekstowa;
	int index_a, index_b;   

	public:
	Tabela();    //konstruktor z domniemanymi wartosciami
	Tabela(int l_k, int l_r, string n_t);    //konstruktor z ustawianymi wartosciami przez uzytkownika
	~Tabela();
	void drukuj();
	void dodaj_rekord();
	void utworz_tabele();
	void zapis_rekordu();
	void zapis_do_pliku();
	void odczyt_z_pliku();
	void wyswietl_rekord();
	void reset_pliku();
	int getTypy_Kolumn(int i);
	int getLiczba_Kolumn();

	void drukuj_bufor();
};

