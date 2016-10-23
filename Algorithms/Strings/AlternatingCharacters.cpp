// AlternatingCharacters.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<string> mystr;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		mystr.push_back(s);
	}

	for (int i = 0; i < n; i++){
		auto it = mystr[i].begin();
		int cnt = 0;
		for (auto it = mystr[i].begin()+1; it != mystr[i].end(); ++it){
			if (*it == *(it - 1)){
				cnt++;
			}
		}
		cout << cnt << endl;
	
	}

	system("pause");
	return 0;
}