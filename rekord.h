#include <iostream>

using namespace std;

class Rekord
{
	private:
	int liczba_kolumn;
	int *typy_kolumn;
	int *kolumny_liczbowe;
	string *kolumny_tekstowe;
	int ilosc_int;
	int ilosc_string;

	int *chwilowa_kolumna_liczbowa;
	string *chwilowa_kolumna_tekstowa;
	
	public:
	Rekord();
	Rekord(const Rekord& r);
	Rekord(int lk, int *tk, int ii, int is);
	~Rekord();
	//void dodaj_rekord(Tabela& t);
	void wypelnij();
	void wyswietl();
	void setLiczba_Kolumn(int lk);
	//void getLiczba_Int(int iint);
	//void getLiczba_String(int istring);

};