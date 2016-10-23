// ConsoleApplication2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Matrix {
	
public:
	int m, n;
	Matrix() {};
	vector<vector<int> > a;
	Matrix(int _m, int _n){
		m = _m, n = _n;
		a.resize(m);
		for (int i = 0; i < m; i++){
			a[i].resize(n);
		}
	}
	Matrix operator + (const Matrix&);
};

Matrix Matrix::operator+ (const Matrix& param){
	int mi, nj;
	mi = a.size();
	nj = a[0].size();
	Matrix temp(mi, nj);
	for (int i = 0; i < mi; i++){
		for (int j = 0; j < nj; j++){
			temp.a[i][j] = a[i][j] + param.a[i][j];
		}
	}
	return temp;
}

int main() {
	int cases, k;
	cin >> cases;
	for (k = 0; k<cases; k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j;
		cin >> n >> m;
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		for (i = 0; i<n; i++) {
			for (j = 0; j<m; j++) {
				cout << y.a[i][j] << " ";
			}
			cout << endl;
		}

		for (i = 0; i<n; i++) {
			for (j = 0; j<m; j++) {
				cout << x.a[i][j] << " ";
			}
			cout << endl;
		}

		result = x + y;
		for (i = 0; i<n; i++) {
			for (j = 0; j<m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

