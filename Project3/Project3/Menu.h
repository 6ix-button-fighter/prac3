#pragma once
#include "Letter.h"
using namespace std;

class Menu {
public:
	void Choice(letter polzovatel[], int count, char* fileName);
	int Quest();
	void Option(letter polzovatel[], int count, char* fileName);
};