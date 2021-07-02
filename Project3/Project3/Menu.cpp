#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Letter.h"
using namespace std;

void Menu::Choice(letter polzovatel[], man manS[], man manR[], int count, char* fileName)
{
	int input;
	cout << endl << "��� ������� �������?" << endl;
	cout << "[1] ������� ����" << endl;
	cout << "[2] �����" << endl << endl;
	cin >> input;

	if (input == 1)
		Option(polzovatel, manS, manR, count, fileName);
	else if (input == 2)
		exit(0);
	else
		cout << "������ �����!" << endl;
}

int Menu::Quest()
{
	int input;

	system("cls");
	printf("��� ������� �������? \n");
	printf("[1] �������� ����������� \n");
	printf("[2] ���������� � ����������� \n");
	printf("[3] ���������� � ����������� \n");
	printf("[4] ����� ����������� \n");
	printf("[5] ���������� \n");
	printf("[6] ����� \n");

	cin >> input;
	return input;
}

void Menu::Option(letter polzovatel[], man manS[], man manR[], int count, char* fileName)
{
	int input = 0;
	letter let;

	while (input != 5)
	{
		input = Quest();
		switch (input)
		{

		case 1:
			getchar();
			let.LoadUser(polzovatel, manS, manR, count, fileName);
			break;

		case 2:
			getchar();
			let.Inf(polzovatel, manS);
			break;

		case 3:
			getchar();
			let.Inf1(polzovatel, manR);
			break;

		case 4:
			getchar();
			let.SearchSender(polzovatel, fileName);
			break;

		case 5:
			getchar();
			let.SortMoney(fileName);
			break;

		case 6:
			exit(0);
			break;

		default:
			printf("�������� ����! \n");
			system("cls");
			break;
		}
		Choice(polzovatel, manS, manR, count, fileName);
	}
}