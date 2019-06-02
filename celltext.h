#include <iostream>
#include <cstdlib>
#include "cell.h"

using namespace std;

class CellText
	: public Cell
{
	protected:
		int *kolumny_liczbowe;
		string *kolumny_tekstowe;
		int *chwilowa_kolumna_liczbowa;
		string *chwilowa_kolumna_tekstowa;
		
		int chwilowa_ilosc_tekstowa;
		int chwilowa_ilosc_liczbowa;

	public:
		CellText();
		~CellText();
		void drukuj_bufor();
		//void wyswietl_rekord();
};
