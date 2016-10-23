// Gemstones.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
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
	map<char,int> bla;

	for (int i = 0; i < n; i++){
		for (auto it = mystr[i].begin(); it != mystr[i].end(); ++it){
			if (i == 0){
				auto x = bla.find(*it);
				if (x == bla.end()){
					bla.insert(make_pair(*it, 0));
				}
			}
			else {
				auto x = bla.find(*it);
				if (x != bla.end() && x->second !=i){
					(x->second)++;
				}
				else if () {

				}
			}
		}
	}

	system("pause");
	return 0;
}
