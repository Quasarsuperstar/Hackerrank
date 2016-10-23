// Warmup.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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
	int a = 0;
	int b = 0;
	int a0;
	int a1;
	int a2;
	cin >> a0 >> a1 >> a2;
	int b0;
	int b1;
	int b2;
	cin >> b0 >> b1 >> b2;
	a0 > b0 ? a++ : (a0 < b0 ? b++ : 0);
	a1 > b1 ? a++ : (a1 < b1 ? b++ : 0);
	a2 > b2 ? a++ : (a2 < b2 ? b++ : 0);
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}
