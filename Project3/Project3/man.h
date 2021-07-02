#pragma once
#include <iostream>
#include "Fio.h"
using namespace std;

class man {
public:
	void setAdress(string adr);
	void setName(string name);
	void setSurname(string name);
	char* getAdress();
	char* getName();
	char* getSurname();
private:
	char adr[50];
	Fio FIO;
};