#pragma once
#include <iostream>
#include "man.h"
#include "Fio.h"
using namespace std;

class letter
{
private:
	double cost;
	int ind1 = 0;
public:
	int count;

	void LoadUser(letter polzovatel[], man manS[], man manR[], int count, char* fileName);
	void SearchSender(letter polzovatel[], char* fileName);
	void SortMoney(char* fileName);
	void Inf(letter polzovatel[], man manS[]);
	void Inf1(letter polzovatel[], man manR[]);

	bool operator==(Fio& obj);
	letter();

	double getCost();
	int getInd();

	void setInd(int id);
	void setCost(double price);
};