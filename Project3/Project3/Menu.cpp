#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Letter.h"
using namespace std;

void Menu::Choice(letter polzovatel[], int count, char* fileName)
{
	int input;
	cout << endl << "Что желаете сделать?" << endl;
	//printf("Что желаете сделать? \n");
	cout << "[1] Галвное меню" << endl;
	//printf("[1] Главное меню \n");
	cout << "[2] Выйти" << endl << endl;
	//printf("[2] Выйти \n");
	cin >> input;
	//scanf("%i", &input);

	if (input == 1)
		Option(polzovatel, count, fileName);
	else if (input == 2)
		exit(0);
	else
		cout << "Ошибка ввода!" << endl;
	//printf("Ошибка ввода! \n");
}

int Menu::Quest()
{
	int input;

	system("cls");
	printf("Что желаете сделать? \n");
	printf("[1] Добавить отправителя \n");
	printf("[2] Информация о получателях \n");
	printf("[3] Информация о отправителе \n");
	printf("[4] Поиск отправителя \n");
	printf("[5] Сортировка \n");
	printf("[6] Выйти \n");

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
			printf("Неверный ввод! \n");
			system("cls");
			break;
		}
		Choice(polzovatel, count, fileName);
	}
}