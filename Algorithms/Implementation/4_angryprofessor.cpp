// angryprofessor.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++){
		int n;
		int k;
		cin >> n >> k;
		vector<int> a(n);
		int ontime=0;
		for (int a_i = 0; a_i < n; a_i++){
			cin >> a[a_i];
			if (a[a_i] <= 0) {
				ontime++;
			}
		}
		if (ontime >= k){
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	system("pause");
	return 0;
}
