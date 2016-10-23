#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uint_64;

int main() {
	uint_64 S, N, P, Q, p231, num, prev, count;
	cin >> N >> S >> P >> Q;
	p231 = pow(2, 31);
	//vector<uint_64> a;
	//a.reserve(N);
	//a.resize(N);
	//a[0] = S % p231;
	//for (uint_64 it = 1; it < N; it++){
	//	a[it] = (a[it-1] * P + Q) % p231;
	//}
	//
	//sort(a.begin(), a.end());
	count = 1;
	prev = S % p231;
	for (uint_64 it = 1; it < N; it++){
		num = (prev * P + Q) % p231;
		if (num != prev){
			count++;
		}
		prev = num;
	}

	//uint_64 count = 1;

	//for (uint_64 i = 1; i < N; i++){
	//	if (a[i] != a[i - 1]){
	//		count++;
	//	}
	//}

	cout << count;

	cout << endl;
	system("pause");
	return 0;
}
