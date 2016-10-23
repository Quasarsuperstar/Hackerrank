// STL2_Vectorerase.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int c;
	cin >> c;
	vector<int> v;
	for (int i = 0; i < c; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int dv;
	cin >> dv;
	v.erase(v.begin()+dv-1);
	int a, b;
	cin >> a >> b;
	v.erase((v.begin()+a-1),(v.begin()+b-1));

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
