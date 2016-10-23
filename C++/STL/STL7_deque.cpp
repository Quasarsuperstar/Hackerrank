// STL7_deque.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <deque> 
using namespace std;
void printKMax(int arr[], int n, int k){
	deque<int> mydeq(k);
	
	int idx = 0;
	while (idx + k < n + 1){
		int max = arr[idx];
		for (int i = idx+1; i < idx + k; i++){
			max = ((max > arr[i]) ? max : arr[i]);
		}
		mydeq.push_front(max);
		idx++;
	}
	while (!mydeq.empty()){
		printf("%d ",mydeq.back());
		mydeq.pop_back();
	}
	cout << endl;
	//Write your code here.
}
int main(){

	int t;
	scanf_s("%d", &t); // cin >> t;
	while (t>0) {
		int n, k;
		scanf_s("%d %d", &n, &k); 
		//cin >> n >> k;
		int i;
		int * arr = new int[n];
		for (i = 0; i < n; i++)
			scanf_s("%d", &arr[i]); 
		// cin >> arr[i];
		printKMax(arr, n, k);
		t--;
		delete[] arr;
	}
	system("pause");
	return 0;
}
