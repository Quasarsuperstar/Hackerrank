// Inheritance3_MultilevelInheritance.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Triangle{
public:
	void triangle(){
		cout << "I am a triangle\n";
	}
};

class Isosceles : public Triangle{
public:
	void isosceles(){
		cout << "I am an isosceles triangle\n";
	}
	void description(){
		cout << "In an isosceles triangle two sides are equal\n";
	}
};

class Equilateral : public Isosceles{
public:
	void equilateral(){
		cout << "I am an equilateral triangle\n";
	}
};

int main(){

	Equilateral eqr;
	eqr.equilateral();
	eqr.isosceles();
	eqr.triangle();
	system("pause");
	return 0;
}