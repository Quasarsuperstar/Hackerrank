// Kangaroos.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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
	int x1;
	int v1;
	int x2;
	int v2;
	double y;
	cin >> x1 >> v1 >> x2 >> v2;
	if (v1 != v2){
		y = (x2 - x1) / (v1 - v2);
	}
	else if (x2==x1)
	{
		y = 1;
	} else y = -1;

	if (((x2 - x1) % (v1 - v2)) == 0 && y > 0) {
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}