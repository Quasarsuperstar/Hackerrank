// Classes8_Cppvariadics.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*************code below**************/
//Enter your code for reversed_binary_value<bool...>

template <bool...digits>
int reversed_binary_value() {
	const size_t size = sizeof...(digits);
	bool bits[size] = { digits... };
	int x = 1;
	int ans = 0;
	for (int i = 0; i < size; i++){
		if (bits[i] == 1){
			ans += x;
		}
		x = 2 * x;
	}
	return ans;
}


/************code above***************/

template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

int main()
{
	int t; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
	system("pause");
}