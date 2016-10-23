#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	vector<int> myvec;
	int tmp;
	char ch;
	stringstream ss(str);
	while (ss >> tmp){
		myvec.push_back(tmp);
		ss >> ch;
	}
	return myvec;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}
	system("pause");
	return 0;
}

