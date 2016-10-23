// ConsoleApplication3.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int n, q, k;
	cin >> n >> q;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++){
		cin >> k;
		arr[i]  = new int[k];
		for (int j = 0; j < k; j++){
			int f;
			cin >> f;
			arr[i][j] = f;
		}
	}

	int** que = new int*[q];
	for (int i = 0; i < q; i++){
		que[i] = new int[2];
		cin >> que[i][0] >> que[i][1];
	}
	for (int i = 0; i < q; i++){
		int m = que[i][0];
		int l = que[i][1];
		cout << arr[m][l] << endl;
	}
	system("pause");
	return 0;
}

