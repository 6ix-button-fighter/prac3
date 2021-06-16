#include "man.h"
#include <iostream>
using namespace std;

void man::setAdress(string adr2) {
	strcpy(adr, adr2.c_str());
}

void man::setName(string name2) {
	strcpy(name, name2.c_str());
}

char* man::getAdress() {
	return adr;
}

char* man::getName() {
	return name;
}
