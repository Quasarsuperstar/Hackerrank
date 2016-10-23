// STL3_LowerBound.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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
	for (int i = 0; i < dv; i++){
		int r;
		cin >> r;
		vector<int>::iterator low;
		low = lower_bound(v.begin(), v.end(), r);
		if (r == *low){
			cout << "Yes ";
		}
		else cout << "No ";
		cout << (low-v.begin()+1) << endl;
	}
	system("pause");
	return 0;
}
