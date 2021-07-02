#pragma once
#include "Letter.h"
using namespace std;

class Menu {
public:
	void Choice(letter polzovatel[], man manS[], man manR[], int count, char* fileName);
	int Quest();
	void Option(letter polzovatel[], man manS[], man manR[], int count, char* fileName);
};