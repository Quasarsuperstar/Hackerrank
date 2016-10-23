// STL1_Vectorsort.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
