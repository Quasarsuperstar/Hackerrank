// STL4_Sets.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	cin >> q;
	set<int> st;
	for (int i = 0; i < q; i++){
		int t, inp;
		cin >> t >> inp;
		switch (t) {
		case 1:
			st.insert(inp);
			break;
		case 2:
			st.erase(inp);
			break;
		case 3:
			if (st.find(inp) == st.end()){
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

