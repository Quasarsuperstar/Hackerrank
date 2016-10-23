// PreprocessorSolution.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#define INF 10000000
#define io(a) cin >> a
#define toStr(x) #x
#define foreach(a, b) for (int b = 0; b < a.size(); ++b)
#define FUNCTION(a,b) inline void a(int &x, int y){(x b y)?false:x=y;}

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
	FUNCTION(maximum, >)

	int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
	system("pause");
	return 0;

}