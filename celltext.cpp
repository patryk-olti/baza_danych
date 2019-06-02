#include <iostream>
#include <cstdlib>
#include "celltext.h"

using namespace std;

CellText::CellText()
{
	kolumny_liczbowe = new int[100];
	kolumny_tekstowe = new string[100];

}

CellText::~CellText(){}

void CellText::drukuj_bufor()
{
	int a = 1;


	cout<<"Komorki tekstowe: "<<endl;
	for(int i=0; i<chwilowa_ilosc_tekstowa ; i++)
	{
		cout<<"Komorka "<<a<<": "<<kolumny_tekstowe[i]<<endl;
		a++;	
	}

	cout<<endl<<"Komorki liczbowe: "<<endl;
	for(int i=0; i<chwilowa_ilosc_liczbowa; i++)
	{
		cout<<"Komorka "<<a<<": "<<kolumny_liczbowe[i]<<" ";
		a++;
	}
}

