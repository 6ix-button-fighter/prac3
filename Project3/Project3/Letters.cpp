#define _CRT_SECURE_NO_WARNINGS
#include "Letters.h"
#include "man.h"
using namespace std;

Letters::Letters() {

}

void Letters::getLetter(letter* pas) {
	delete[] this->pas;
	this->pas = new letter[pas->count];
	for (int i = 0; i < pas->count; i++) {
		this->pas[i] = pas[i];
	}
	this->count = count;
}

letter* Letters::getLetter() {
	return pas;
}

int Letters::getI()
{
	return i;
}

void Letters::setI(int num) {
	i = num;
}

void Letters::LoadUser(letter polzovatel[], int count, char* fileName)
{
	man a;
	string name, adress;
	double price;

	system("cls");
	FILE* fileWrite;
	fileWrite = fopen(fileName, "a+");

	if (fileWrite != NULL)
	{
		if (i < count)
		{
			printf("Введите имя получателя: ");
			cin >> name;
			polzovatel[i].setName1(name);
			a.setName(name);
			polzovatel[i].setInd(i++);
			fprintf(fileWrite, "Имя: %s \n", a.getName());
			printf("Введите имя отправителя: ");
			cin >> name;
			polzovatel[i].setName2(name);
			polzovatel[i].setInd(i+(i-1));
			fprintf(fileWrite, "Имя: %s \n", polzovatel[i].getName2());
			printf("Введите адрес отправления: ");
			getchar();
			cin >> adress;
			polzovatel[i].setAdress1(adress);
			a.setAdress(adress);
			fprintf(fileWrite, "Адрес отправления: %s \n", a.getAdress());
			printf("Введите адрес отправления: ");
			cin >> adress;
			polzovatel[i].setAdress2(adress);
			fprintf(fileWrite, "Адрес отправителя: %s \n", polzovatel[i].getAdress2());
			printf("Введите цену письма: ");
			cin >> price;
			polzovatel[i].setCost(price);
			fprintf(fileWrite, "Цена письма: %lf \n\n", polzovatel[i].getCost());
			i++;
		}
		else
			cout << "Больше не существует пользователей!" << endl;
	}
	else
		printf("Не удалось открыть файл \n");
	fclose(fileWrite);
}

void Letters::SearchSender(letter polzovatel[], char* fileName)
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
			//fscanf(fileWrite, "%s", &text);

			if (feof(fileWrite))
				break;
			else {
				//printf("%s \n", text);
				cout << "  " << text << endl;
				y++;
			}
		}

		for (int j = 3; j < y; j += 13) {
			if (text[j] == sName[y]) {
				for (int k = j - 3; k < j + 10; k++)
					//printf(" ", text[k]);
				//printf("\n");
					cout << " " << text[k];
				cout << endl;
			}
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fclose(fileWrite);
}

void Letters::SortMoney(char* fileName) {

	system("cls");
	FILE* fileWrite;
	fileWrite = fopen(fileName, "a+");
	string text[256];
	string sText;
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
				//printf("%s ", text);
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
							//printf("\n \n");
							cout << endl << endl;
						//printf(" ", text[n]);
						cout << " " << text[n];
					}
					//printf("\n");
					cout << endl;
				}
			}
		}
	}
	else cerr << "Не удалось открыть файл\n";
	fclose(fileWrite);
}

bool Letters::operator==(Fio& obj) {
	if ((strcmp(this->fio.getSurname(), obj.getSurname()) == 0) &&
		(strcmp(this->fio.getName(), obj.getName()) == 0) &&
		(strcmp(this->fio.getFather(), obj.getFather()) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bool Letters::operator!(letter polzovatel)
//bool Letters::operator<=(letter polzovatel)
//{
//	//letter polzovatel[i];
//	char tmp[50];
//	man man;
//
//	for (int j = 0; j <= i - 1; j++)
//		for (int k = j + 1; k <= i; k++)
//			if (strcmp(polzovatel[j], polzovatel[k]) > 0) {
//				strcpy(tmp, polzovatel[j]);
//				strcpy(polzovatel[j], polzovatel[k]);
//				strcpy(polzovatel[k], tmp);
//			}
//}