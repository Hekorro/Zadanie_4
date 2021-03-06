// Zadanie_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#define rozmiar 10
using namespace std;

class Stos
{
public:

	
	int *tab;
	int aktualny;
	int rozmiar_stosu;

	Stos()
	{

	}

	Stos(int b)
	{
		rozmiar_stosu = b;
		init(rozmiar_stosu);
		cout << "ZAINICJOWANO NOWY STOS" << endl;
		cout << "ADRES TO: " << this << endl;
	}
	~Stos()
	{
		cout << "USUNIETO STOS" << endl;
		cout << "ADRES TO: " << this << endl;
		destroy();
	}

	void init(int zmienna)
	{
		tab = new int[zmienna];
		aktualny = -1;
	}
	void destroy()
	{
		delete[] tab;
		tab = NULL;
		aktualny = -1;
	}

	void pop()
	{
		if (aktualny > -1)
			--aktualny;
		else
			return;
	}
	void push(int x)
	{
		if (aktualny < rozmiar - 1)
		{
			++aktualny;
			tab[aktualny] = x;
		}
		else
			cout << "Stos jest pelny" << endl;
	}
	int top()
	{
		if (aktualny <= -1)
			return 0;
		else
			return tab[aktualny];
	}
	int empty()
	{
		if (aktualny == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int full()
	{
		if (aktualny == (rozmiar - 1))
			return 1;
		else return 0;
	}

};

void dodaj(Stos &s, int a)
{
	s.push(a);
}

int main()
{
	/*Stos stos1(rozmiar);
	int i, liczba;
	for (i = 0; i < rozmiar; i++)
	{
		cout << "Podaj " << i + 1 << " element stosu" << endl;
		cin >> liczba;
		stos1.push(liczba);
	}
	cout << "\n";
	Stos *stos2;
	stos2=new Stos(rozmiar);
	for (i = 0; i < rozmiar; i++)
	{
		stos2->push(stos1.top());
		stos1.pop();
		cout << stos2->top() << endl;
	}
	*/
	Stos s(rozmiar);
	s.push(0);
	dodaj(s, 1);
	dodaj(s, 2);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	s.destroy();
	system("pause");
	return 0;
}
