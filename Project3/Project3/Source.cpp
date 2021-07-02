#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include "Menu.h"
#include "Letter.h"
using namespace std;

letter::letter() {
	int l;
}
 
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char nameFile[15] = "polzovatel.txt";
	int countPolzovatel;
	letter* pas;
	letter l;
	Menu m;

	cout << "¬ведите количество пар пользователей: ";
	cin >> countPolzovatel;

	pas = new letter[countPolzovatel]();
	FILE* fileRead;

	if ((fileRead = fopen("polzovatel.txt", "rb+")) == NULL)
	{
		getchar();
		l.LoadUser(pas, countPolzovatel, nameFile);
		m.Choice(pas, countPolzovatel, nameFile);
	}

	m.Option(pas, countPolzovatel, nameFile);

	delete[] pas;
}