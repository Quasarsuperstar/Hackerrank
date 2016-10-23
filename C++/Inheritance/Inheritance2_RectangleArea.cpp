// Inheritance2_RectangleArea.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	virtual void display(){
		printf("%d %d\n", width, height);
	}
	
};

class RectangleArea : public Rectangle {
public:
	void read_input(){
			cin >> width >> height;
		}
	void display(){
		//Rectangle::display();
		int a = width*height;
		printf("%d\n", a);
	}

};

int main()
{
	/*
	* Declare a RectangleArea object
	*/
	RectangleArea r_area;

	/*
	* Read the width and height
	*/
	r_area.read_input();

	/*
	* Print the width and height
	*/
	r_area.Rectangle::display();

	/*
	* Print the area
	*/
	r_area.display();
	system("pause");
	return 0;
}