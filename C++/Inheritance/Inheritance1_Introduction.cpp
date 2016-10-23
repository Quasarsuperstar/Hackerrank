// Inheritance1_Introduction.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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
int main(){
	Isosceles isc;
	isc.isosceles();
	isc.description();
	isc.triangle();
	system("pause");
	return 0;
}
