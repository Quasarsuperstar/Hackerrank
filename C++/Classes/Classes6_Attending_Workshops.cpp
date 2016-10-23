#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops {
	int n;
	vector<Workshop> shops;
};



Available_Workshops* initialize(int start_time[], int duration[], int n){
	Available_Workshops * temp = new Available_Workshops;
	temp->n = n;
	temp->shops.resize(n);
	for (int i = 0; i < n; i++){
		temp->shops[i].duration = duration[i];
		temp->shops[i].start_time = start_time[i];
		temp->shops[i].end_time = start_time[i] + duration[i];
	}
	return temp;
}
int soonest_end(Available_Workshops* drp, int curtime){
	int ende= 1000000;
	for (int i = 0; i < drp->n; i++){
		if (drp->shops[i].start_time >= curtime && drp->shops[i].end_time < ende)
			ende = drp->shops[i].end_time;
	}
	return ende;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
	int timmy=0;
	int its = 0;
	int lasttime = 0;
	for (int i = 0; i < ptr->n; i++){
		if (ptr->shops[i].end_time > lasttime){
			lasttime = ptr->shops[i].end_time;
		}
	}
	while (its < lasttime){
		its = soonest_end(ptr, its);
		timmy++;
		//cout << "iter = " << timmy << "\t its = " << its << endl;
	}
	if (its == 1000000){
		timmy--;
	}
	return timmy;
}

int main()
{
	int n;
	cin >> n;
	int * start_time = new int[n];
	int * duration = new int[n];
	int tmp;
	for (int i = 0; i<n; i++)
	{
		cin >> tmp;
		start_time[i] = tmp;
	}
	for (int i = 0; i<n; i++)
	{
		cin >> tmp;
		duration[i] = tmp;
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;

	system("pause");
	return 0;
}
