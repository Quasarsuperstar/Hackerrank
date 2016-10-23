// STL5_Maps.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int q;
	cin >> q;
	map<string,int> m;
	for (int i = 0; i < q; i++){
		int t, inp;
		string studi;
		cin >> t; 
		cin >> studi;
		map<string, int>::iterator itr = m.find(studi);
		switch (t) {
		case 1:
			cin >> inp;
			if (itr == m.end()){
				m.insert(make_pair(studi, inp));
			}
			else {
				itr->second +=inp;
			}
			break;
		case 2:
			m.erase(studi);
			break;
		case 3:
			
			if (itr == m.end()){
				cout << 0 << endl;
			}
			else {
				cout << itr->second << endl;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

