// timeconversion.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string time;
	cin >> time;
	//"07:05:45PM"

	if (time.substr(8, 9) == "PM" && time.substr(0, 2) != "12") {
		time[0] += 1;
		time[1] += 2;
	}
	else if (time.substr(8, 9) == "AM" && time.substr(0, 2) == "12") {
		time[0] = '0';
		time[1] = '0';
	}
	time.erase(8, 9);
	cout << time << endl;
	system("pause");
	return 0;
}