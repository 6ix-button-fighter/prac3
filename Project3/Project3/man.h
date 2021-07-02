#pragma once
#include <iostream>
using namespace std;

class man {
public:
	void setAdress(string adr);
	void setName(string name);
	char* getAdress();
	char* getName();
private:
	char adr[50];
	char name[50];
};


/*	delete[] this->adr;
	this->adr = new char[adr->count];
	for (int i = 0; i < adr->count; i++) {
		this->adr[i] = adr[i];
	}
	this->count = count;
}

char* man::getAdr() {
	return man;
}*/
