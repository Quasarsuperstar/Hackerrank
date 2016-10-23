#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student {
private:
	vector<int> scores;
	int totscore;
public:
	Student(){
		totscore = 0;
	}
	void input(){
		int num;
		for (int i = 0; i < 5; i++){
			cin >> num;
			scores.push_back(num);
			totscore += num;
		}
	}
	int calculateTotalScore(){
		return totscore;
	}
};


int main() {
	int n; // number of students
	cin >> n;
	Student *s = new Student[n]; // an array of n students

	for (int i = 0; i < n; i++){
		s[i].input();
	}

	// calculate kristen's score
	int kristen_score = s[0].calculateTotalScore();

	// determine how many students scored higher than kristen
	int count = 0;
	for (int i = 1; i < n; i++){
		int total = s[i].calculateTotalScore();
		if (total > kristen_score){
			count++;
		}
	}

	// print result
	cout << count;

	system("pause");
	return 0;
}

