// Arrayrotation.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, k, q;
	cin >> n >> k >> q;
	int x = k % n;
	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++){
		cin >> arr[x];
		x++;
		x %= n;
	}
	for (int i = 0; i < q; i++){
		int f;
		cin >> f;
		cout << arr[f] << endl;
	}
	system("pause");
		return 0;
}
