#pragma once
#include "Letter.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int countPeople = 0;

//letter::letter(letter& obj)
//{
//	this->count++;
//	this->Man.setAdress(obj.Man.getAdress());
//	this->Man.setName(obj.Man.getName());
//}

void letter::Inf(letter polzovatel[])
{
	system("cls");
	double sum = 0.0;

	printf("Имя \t\tЦена \tИндекс \n");
	printf("Получателя \t(руб) \t(номер) \n");
	printf("----------------------------------------- \n");

	for (int j = 0; j < countPeople; j++) {
		printf("%s \t\t%.2lf \t%i \n", polzovatel[j].name1, polzovatel[j].cost, polzovatel[j].ind1);
		sum += polzovatel[j].cost;
	}

	printf("----------------------------------------- \n");
	printf("Всего \t\t%.2lf рублей \n", sum);
	printf("Количество записей в базе \t%i \n", countPeople);
}

void letter::Inf1(letter polzovatel[])
{
	system("cls");
	double sum = 0.0;

	cout << "Имя    Цена   Индекс" << endl;
	cout << "Отправителя   (руб)   (номер)" << endl;
	cout << "-----------------------------------------" << endl;

	for (int j = 0; j < countPeople; j++) {
		cout << polzovatel[j].getName2() << "   " << polzovatel[j].getCost() << "   " << polzovatel[j].getInd() << endl;
		sum += polzovatel[j].getCost();
	}

	cout << "-----------------------------------------" << endl;
	cout << "Всего рублей: " << sum << endl;
	cout << "Количество записей в базе: " << countPeople << endl;

}

void letter::LoadUser(letter polzovatel[], int count, char* fileName)
{
	man a;
	string name, adress;
	double price;

	system("cls");
	FILE* fileWrite;
	fileWrite = fopen(fileName, "a+");

	if (fileWrite != NULL)
	{
		if (countPeople < count) {
			printf("Введите имя получателя: ");
			cin >> name;
			polzovatel[countPeople].setName1(name);
			a.setName(name);
			cout << "Число name: " << countPeople << endl;
			polzovatel[countPeople].setInd(countPeople + 1);
			cout << "Число setInd: " << countPeople << endl;
			fprintf(fileWrite, "Имя: %s \n", a.getName());
			printf("Введите имя отправителя: ");
			cin >> name;
			polzovatel[countPeople].setName2(name);
			polzovatel[countPeople].setInd(countPeople + 2);
			cout << "Число setInd: " << countPeople << endl;
			fprintf(fileWrite, "Имя: %s \n", polzovatel[countPeople].getName2());
			printf("Введите адрес отправления: ");
			getchar();
			cin >> adress;
			polzovatel[countPeople].setAdress1(adress);
			a.setAdress(adress);
			fprintf(fileWrite, "Адрес отправления: %s \n", a.getAdress());
			printf("Введите адрес отправления: ");
			cin >> adress;
			polzovatel[countPeople].setAdress2(adress);
			fprintf(fileWrite, "Адрес отправителя: %s \n", polzovatel[countPeople].getAdress2());
			printf("Введите цену письма: ");
			cin >> price;
			polzovatel[countPeople].setCost(price);
			fprintf(fileWrite, "Цена письма: %lf \n\n", polzovatel[countPeople].getCost());
			countPeople++;
			cout << "Число: " << countPeople << endl;
		}
		else
			printf("Невозможно! \n");
	}
	else
		printf("Не удалось открыть файл \n");
	fclose(fileWrite);
}

void letter::SearchSender(letter polzovatel[], char* fileName)
{
	system("cls");
	FILE* fileWrite;
	fileWrite = fopen(fileName, "a+");
	char text[256], sText[20], sName[20];
	int y = 0;

	if (fileWrite != NULL)
	{
		cout << "Введите имя отправителя: ";
		cin >> sName;

		while (1) {
			if (feof(fileWrite))
				break;
			else {
				cout << "  " << text << endl;
				y++;
			}
		}

		for (int j = 3; j < y; j += 13) {
			if (text[j] == sName[y]) {
				for (int k = j - 3; k < j + 10; k++)
					cout << " " << text[k];
				cout << endl;
			}
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fclose(fileWrite);
}

void letter::SortMoney(char* fileName) {

	system("cls");
	FILE* fileWrite;
	fileWrite = fopen(fileName, "a+");
	string text[256], sText;
	int y = 0, second = 0, first = 0;

	double* secondPrice, * firstPrice;
	secondPrice = new double[count];
	firstPrice = new double[count];

	if (fileWrite != NULL)
	{
		while (1) {
			fscanf(fileWrite, "%s", &text);
			if (feof(fileWrite))
				break;
			else {
				cout << "  " << text;
				y++;
			}
		}

		for (int j = 12; j < y; j += 13) { // 12 25 38
			secondPrice[j - 12] = atof(text[j].c_str());
			second++;
			firstPrice[j - 12] = atof(text[j].c_str());
			first++;
		}

		for (int j = 0; j < second; j++) {
			for (int k = 0; k < second - 1; k++) {
				if (secondPrice[k] > secondPrice[k + 1]) {

					double b = secondPrice[k]; // создали дополнительную переменную
					secondPrice[k] = secondPrice[k + 1]; // меняем местами
					secondPrice[k + 1] = b; // значения элементов
				}
			}
		}

		for (int j = 0; j < second; j++) {
			for (int k = 0; k < first; k++) {
				if (secondPrice[j] == firstPrice[k]) {
					int pos = 12;

					if (k > 0)
						pos = (k + 1) * 12 + k;
					for (int n = pos - 12; n < pos + 1; n++) {
						if (n == 0)
							cout << endl << endl;
						cout << " " << text[n];
					}
					cout << endl;
				}
			}
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fclose(fileWrite);
}

bool letter::operator==(Fio& obj) {
	if ((strcmp(this->fio.getSurname(), obj.getSurname()) == 0) &&
		(strcmp(this->fio.getName(), obj.getName()) == 0) &&
		(strcmp(this->fio.getFather(), obj.getFather()) == 0))
		return true;
	else
		return false;
}

char* letter::getName1() { return name1; }
char* letter::getName2() { return name2; }
char* letter::getAdress1() { return adres1; }
char* letter::getAdress2() { return adres2; }
double letter::getCost() { return cost; }
int letter::getInd() { return ind1; }

void letter::setName1(string name) { strcpy(name1, name.c_str()); }
void letter::setName2(string name) { strcpy(name2, name.c_str()); }
void letter::setAdress1(string adress) { strcpy(adres1, adress.c_str()); }
void letter::setAdress2(string adress) { strcpy(adres2, adress.c_str()); }
void letter::setInd(int id) { ind1 = id; }
void letter::setCost(double price) { cost = price; }