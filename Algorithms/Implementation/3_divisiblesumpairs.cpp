// divisiblesumpairs.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	int x = 0;
	for (int a_i = 0; a_i < n; a_i++){
		cin >> a[a_i];
		for (int j = 0; j < a_i; j++){
			if ((a[j] + a[a_i]) % k == 0){
				x++;
			}
		}
	}
	cout << x << endl;
	system("pause");
	return 0;
}
