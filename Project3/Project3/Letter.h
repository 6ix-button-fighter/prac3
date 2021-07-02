#pragma once
#include <iostream>
#include "man.h"
#include "Fio.h"
using namespace std;

class letter
{
private:
	char adres1[50];
	char adres2[50];
	char name1[50];
	char name2[50];
	double cost;
	int ind1 = 0;

	man Man;
	Fio fio;
public:
	int count;

	void LoadUser(letter polzovatel[], int count, char* fileName);
	void SearchSender(letter polzovatel[], char* fileName);
	void SortMoney(char* fileName);
	void Inf(letter polzovatel[]);
	void Inf1(letter polzovatel[]);

	bool operator==(Fio& obj);
	bool operator<=(letter polzovatel);
	letter(letter& obj);
	letter();

	char* getName1();
	char* getName2();
	char* getAdress1();
	char* getAdress2();
	double getCost();
	int getInd();
	 
	void setName1(string name);
	void setName2(string name);
	void setAdress1(string adress);
	void setAdress2(string adress);
	void setInd(int id);
	void setCost(double price);
};