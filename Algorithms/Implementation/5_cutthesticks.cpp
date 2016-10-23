// cutthesticks.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++){
		cin >> arr[arr_i];
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	while (!arr.empty()){
		cout << arr.size() << endl;
		vector<int>::iterator it=arr.begin();
		while(it!=arr.end() && !arr.empty()){
			*it -= arr.back();
			it++;
		}
		while (!arr.empty() && arr.back() <= 0){
			arr.pop_back();
		}
	}
	system("pause");
	return 0;
}
