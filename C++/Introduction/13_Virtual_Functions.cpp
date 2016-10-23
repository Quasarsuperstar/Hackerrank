// ConsoleApplication5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static int scount,pcount;

class Person {
private:
	string name;
	int age;
public:
	virtual void getdata(){
		cin >> name;
		cin >> age;
	}
	virtual void putdata(){
		cout << name << " " << age << " ";
	}
};

class Professor : public Person {
private:
	int cur_id;
	int publications;
public:
	Professor(){
		pcount++;
		cur_id = pcount;
	}
	void getdata(){
		Person::getdata();
		cin >> publications;
	}
	void putdata(){
		Person::putdata();
		cout << publications << " " << cur_id << endl;
	}
};

class Student : public Person {
private:
	int cur_id;
	int marksum;
public:
	Student(){
		scount++;
		cur_id = scount;
	}
	void getdata(){
		Person::getdata();
		marksum = 0;
		for (int i = 0; i < 6; i++){
			int inp;
			cin >> inp;
			marksum += inp;
		}
	}
	void putdata(){
		Person::putdata();
		cout << marksum << " " << cur_id << endl;
	}
};



int main(){
	int val;
	const int n = 4;
//	cin >> n; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++){

		cin >> val;
		if (val == 1){
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i<n; i++)
		per[i]->putdata(); // Print the required output for each object.
	system("pause");
	return 0;

}
