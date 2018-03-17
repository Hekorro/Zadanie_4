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
	Stos()
	{
		aktualny = -1;
	}

	void init(int zmienna)
	{
		tab = new int[zmienna];
		aktualny = -1;
	}
	void destroy()
	{
		delete[] tab;
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
			aktualny++;
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

int main()
{
	Stos stos1, stos2;
	int i, liczba;
	stos1.init(rozmiar);
	for (i = 0; i < rozmiar; i++)
	{
		cout << "Podaj " << i + 1 << " element stosu" << endl;
		cin >> liczba;
		stos1.push(liczba);
	}
	cout << "\n";
	stos2.init(rozmiar);
	for (i = 0; i < rozmiar; i++)
	{
		stos2.push(stos1.top());
		stos1.pop();
		cout << stos2.top() << endl;
	}
	stos1.destroy();
	stos2.destroy();
	return 0;
}
