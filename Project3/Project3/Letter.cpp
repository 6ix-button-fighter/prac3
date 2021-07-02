#pragma once
#include "Letter.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countPeople = 0;

void letter::Inf(letter polzovatel[], man manS[])
{
	system("cls");
	double sum = 0.0;

	printf("Имя \t\tЦена \tИндекс \n");
	printf("Получателя \t(руб) \t(номер) \n");
	printf("----------------------------------------- \n");

	for (int j = 0; j < countPeople; j++) {
		printf("%s \t\t%.2lf \t%i \n", manS[j].getName(), polzovatel[j].cost, polzovatel[j].ind1 - 2);
		sum += polzovatel[j].cost;
	}

	printf("----------------------------------------- \n");
	printf("Всего \t\t%.2lf рублей \n", sum);
	printf("Количество записей в базе \t%i \n", countPeople);
}

void letter::Inf1(letter polzovatel[], man manR[])
{
	system("cls");
	double sum = 0.0;

	printf("Имя \t\tЦена \tИндекс \n");
	printf("Отправителя \t(руб) \t(номер) \n");
	printf("----------------------------------------- \n");

	for (int j = 0; j < countPeople; j++) {
		cout << manR[j].getName() << "\t\t" << polzovatel[j].getCost() << "\t" << polzovatel[j].getInd() - 2 << endl;
		sum += polzovatel[j].getCost();
	}

	printf("----------------------------------------- \n");
	printf("Всего \t\t%.2lf рублей \n", sum);
	printf("Количество записей в базе \t%i \n", countPeople);

}

void letter::LoadUser(letter polzovatel[], man manS[], man manR[], int count, char* fileName)
{
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
			manS[countPeople].setName(name);
			polzovatel[countPeople].setInd(countPeople + 1);
			fprintf(fileWrite, "Получатель: %s \n", manS[countPeople].getName());
			printf("Введите имя отправителя: ");
			cin >> name;
			manR[countPeople].setName(name);
			polzovatel[countPeople].setInd(countPeople + 2);
			fprintf(fileWrite, "Отправитель: %s \n", manR[countPeople].getName());
			printf("Введите адрес получателя: ");
			getchar();
			cin >> adress;
			manS[countPeople].setAdress(adress);
			fprintf(fileWrite, "Адрес получателя: %s \n", manS[countPeople].getAdress());
			printf("Введите адрес отправления: ");
			cin >> adress;
			manR[countPeople].setAdress(adress);
			fprintf(fileWrite, "Адрес отправителя: %s \n", manR[countPeople].getAdress());
			printf("Введите цену письма: ");
			cin >> price;
			polzovatel[countPeople].setCost(price);
			fprintf(fileWrite, "Цена письма: %lf \n\n", polzovatel[countPeople].getCost());
			countPeople++;
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
	ifstream fileWrite(fileName);	
	string searchName, line[256];
	int countLine = 0, point = -1;

	if (fileWrite.is_open())
	{
		cout << "Введите нужное имя: ";
		cin >> searchName;
		cout << endl;

		while (getline(fileWrite, line[countLine]))
		{
			if (countLine % 6 == 0)
				if (line[countLine].find(searchName) != -1)
					point = countLine;

			if (point >= 0 && countLine == point + 5)
				for (int n = point; n < point + 5; n++)
					cout << line[n] << endl;

			countLine++;
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fileWrite.close();
}

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void letter::SortMoney(char* fileName) {

	system("cls");
	ifstream fileWrite(fileName);
	string text[256], sText;
	int y = 0, second = 0, first = 0;

	double *secondPrice = new double[count], 
		   *firstPrice = new double[count];

	if (fileWrite.is_open())
	{
		while (!fileWrite.eof()) {
			fileWrite >> text[y];
			y++;
		}

		for (int j = 12; j < y; j += 13) {
			secondPrice[second] = atof(text[j].c_str());
			firstPrice[second] = atof(text[j].c_str());
			second++;
		}

		for (int j = 0; j < second; j++) {
			for (int k = 0; k < second - 1; k++) {
				if (secondPrice[k] > secondPrice[k + 1]) {

					double b = secondPrice[k];
					secondPrice[k] = secondPrice[k + 1];
					secondPrice[k + 1] = b;
				}
			}
		}

		for (int j = 0; j < second; j++) {
			for (int k = 0; k < second; k++) {
				if (secondPrice[j] == firstPrice[k]) {
					int pos = 12;

					if (k > 0)
						pos = (k + 1) * 12 + k;
					for (int n = pos - 12; n < pos + 1; n++) {
						cout << " " << text[n];
					}
					cout << endl;
				}
				else continue;
			}
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fileWrite.close();
}

bool letter::operator==(Fio& obj) {
	man* manS = new man[countPeople];
	if ((strcmp(manS[countPeople].getSurname(), obj.getSurname()) == 0) &&
		(strcmp(manS[countPeople].getName(), obj.getName()) == 0))
		return true;
	else
		return false;
}

double letter::getCost() { return cost; }
int letter::getInd() { return ind1; }

void letter::setInd(int id) { ind1 = id; }
void letter::setCost(double price) { cost = price; }