#define _CRT_SECURE_NO_WARNINGS
#include "Fio.h"
#include <iostream>
using namespace std;

char* Fio::getSurname() { return surname; }
char* Fio::getName() { return name; }

void Fio::setSurname(string surname2) { strcpy(surname, surname2.c_str()); }
void Fio::setName(string name2) { strcpy(name, name2.c_str()); }