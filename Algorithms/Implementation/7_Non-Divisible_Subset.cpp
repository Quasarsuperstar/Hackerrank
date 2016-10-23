// Non-Divisible_Subset.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	multimap<int, int> m;
	int min = 2147483647;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		x %= k;
	//	multimap<int, int>::iterator it = m.find(x);
		auto it = m.find(x);
		if (it == m.end()){
			m.insert(make_pair(x, 1));
		}
		else {
			it->second++;
		}
	}
	multimap<int, int>::iterator it = m.begin();
	int count = n;
	while (it != m.end()){
		multimap<int, int>::iterator it2 = m.find((k-(it->first))%k);
		if (it2 != m.end() && it2 != it){
			count -= (it->second < it2->second) ? it->second : it2->second;
			m.erase(it2);
		}
		else if (it2 == it){
			count -= it->second - 1;

		}
		it++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}

