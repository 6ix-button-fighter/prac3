#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Letter.h"
using namespace std;

void Menu::Choice(letter polzovatel[], int count, char* fileName)
{
	int input;
	cout << endl << "��� ������� �������?" << endl;
	//printf("��� ������� �������? \n");
	cout << "[1] ������� ����" << endl;
	//printf("[1] ������� ���� \n");
	cout << "[2] �����" << endl << endl;
	//printf("[2] ����� \n");
	cin >> input;
	//scanf("%i", &input);

	if (input == 1)
		Option(polzovatel, count, fileName);
	else if (input == 2)
		exit(0);
	else
		cout << "������ �����!" << endl;
	//printf("������ �����! \n");
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

void Menu::Option(letter polzovatel[], int count, char* fileName)
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
			let.LoadUser(polzovatel, count, fileName);
			break;

		case 2:
			getchar();
			let.Inf(polzovatel);
			break;

		case 3:
			getchar();
			let.Inf1(polzovatel);
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
		Choice(polzovatel, count, fileName);
	}
}