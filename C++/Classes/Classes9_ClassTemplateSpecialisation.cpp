// ConsoleApplication18.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


#include <iostream>
#include <string>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
//template <> struct Traits < Color > { static string name(int i){ 
//	if (true){
//		return "unknown";
//	}
//	else return "unknown";
//}};	

template <> struct Traits <Color> {
		static string name(int idx){
				if (idx == 0){
					return "apple";
				}
				else if (idx == 1){
					return "orange";
				}
				else if (idx == 2){
					return "pear";
				}
				else { return "unknown";
					}
	}
};
template <> struct Traits < Fruit > {
	static string name(int idx){
		if (idx == 0){
			return "red";
		}
		else if (idx == 1){
			return "green";
		}
		else if (idx == 2){
			return "orange";
		}
		else {
			return "unknown";
		}
	}
};

int main()
{
	int t = 0; std::cin >> t;
//	std::string lol = "orange";
	for (int i = 0; i != t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
//		cout << lol << " ";
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
	system("pause");
	return 0;
}
