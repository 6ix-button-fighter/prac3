#pragma once
#include <iostream>
using namespace std;

class Fio
{
private:
	char surname[50];
	char name[50];
public:
	char* getSurname();
	char* getName();

	void setSurname(string surname);
	void setName(string name);
};