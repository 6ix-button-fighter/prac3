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
	int countPolzovatel = 0;
	letter* pas;
	man *manS = new man[countPolzovatel], *manR = new man[countPolzovatel];
	letter l;
	Menu m;

	cout << "������� ���������� ��� �������������: ";
	cin >> countPolzovatel;

	pas = new letter[countPolzovatel]();
	FILE* fileRead;

	if ((fileRead = fopen("polzovatel.txt", "rb+")) == NULL)
	{
		getchar();
		l.LoadUser(pas, manS, manR, countPolzovatel, nameFile);
		m.Choice(pas, manS, manR, countPolzovatel, nameFile);
	}

	m.Option(pas, manS, manR, countPolzovatel, nameFile);

	delete[] pas;
}