#pragma once
#include "Letter.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
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
		printf("%s \t\t%.2lf \t%i \n", polzovatel[j].name1, polzovatel[j].cost, polzovatel[j].ind1 - 2);
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

	printf("Имя \t\tЦена \tИндекс \n");
	printf("Получателя \t(руб) \t(номер) \n");
	printf("----------------------------------------- \n");

	for (int j = 0; j < countPeople; j++) {
		cout << polzovatel[j].getName2() << "\t\t" << polzovatel[j].getCost() << "\t" << polzovatel[j].getInd() - 2 << endl;
		sum += polzovatel[j].getCost();
	}

	printf("----------------------------------------- \n");
	printf("Всего \t\t%.2lf рублей \n", sum);
	printf("Количество записей в базе \t%i \n", countPeople);

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
			polzovatel[countPeople].setInd(countPeople + 1);
			fprintf(fileWrite, "Получатель: %s \n", a.getName());
			printf("Введите имя отправителя: ");
			cin >> name;
			polzovatel[countPeople].setName2(name);
			polzovatel[countPeople].setInd(countPeople + 2);
			fprintf(fileWrite, "Отправитель: %s \n", polzovatel[countPeople].getName2());
			printf("Введите адрес получателя: ");
			getchar();
			cin >> adress;
			polzovatel[countPeople].setAdress1(adress);
			a.setAdress(adress);
			fprintf(fileWrite, "Адрес получателя: %s \n", a.getAdress());
			printf("Введите адрес отправления: ");
			cin >> adress;
			polzovatel[countPeople].setAdress2(adress);
			fprintf(fileWrite, "Адрес отправителя: %s \n", polzovatel[countPeople].getAdress2());
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
			if (countLine % 6 == 0) {
				if (line[countLine].find(searchName) != -1)
					point = countLine;
			}

			if (point >= 0 && countLine == point + 6)
				for (int n = point; n < point + 6; n++)
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