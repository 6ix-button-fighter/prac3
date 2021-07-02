#include "man.h"
#include <iostream>
using namespace std;

char* man::getSurname() { return FIO.getSurname(); }
char* man::getAdress() { return adr; }
char* man::getName() { return FIO.getName(); }

void man::setAdress(string adr2) { strcpy(adr, adr2.c_str()); }
void man::setName(string name2) { FIO.setName(name2.c_str()); }
void man::setSurname(string surname2) { FIO.setSurname(surname2.c_str()); }