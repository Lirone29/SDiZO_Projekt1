#include "stdafx.h"
#include "textMenu.h"
#include <iostream>
using namespace std;

void textMenu::dispalyChoose()
{
	cout << "Wybierz jaka operacje chcesz wykonac:" << endl;
	cout << "1. Zbuduj z pliku" << endl;
	cout << "2. Usun" << endl;
	cout << "3. Dodaj" << endl;
	cout << "4. Znajdz" << endl;
	cout << "5. Wyswietl " << endl;
	cout << "6. Exit" << endl;
	return;
}

textMenu::textMenu()
{
}


textMenu::~textMenu()
{
}
