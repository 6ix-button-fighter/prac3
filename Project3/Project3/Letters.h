#pragma once
#include <iostream>
#include "Letter.h"
#include "Fio.h"
#include "man.h"
using namespace std;

class Letters
{
	letter* pas;
	int count;
	Fio fio;
public:
	int i = 1;
	void LoadUser(letter polzovatel[], int count, char* fileName);
	void SearchSender(letter polzovatel[], char* fileName);
	void SortMoney(char* fileName);

	bool operator==(Fio& obj);
	bool operator<=(letter polzovatel);
	//Пер

	int getI();
	void setI(int num);

	Letters();
	letter* getLetter();
	void getLetter(letter* pas);
};