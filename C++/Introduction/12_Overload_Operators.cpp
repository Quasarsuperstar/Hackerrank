//Operator Overloading

#include "stdafx.h"
#include<iostream>


using namespace std;

class Complex
{
public:
	int a, b;
	void input(string s)
	{
		int v1 = 0;
		int i = 0;
		while (s[i] != '+')
		{
			v1 = v1 * 10 + s[i] - '0';
			i++;
		}
		while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
		{
			i++;
		}
		int v2 = 0;
		while (i<s.length())
		{
			v2 = v2 * 10 + s[i] - '0';
			i++;
		}
		a = v1;
		b = v2;
	}
};

Complex operator+ (const Complex& arg1, const Complex arg2){
	Complex temp;
	temp.a = arg1.a + arg2.a;
	temp.b = arg1.b + arg2.b;
	return temp;
}

ostream& operator<< (ostream &out, const Complex& arg1){
	out << arg1.a << ' + i' << arg1.b;
	return out;
}

int main()
{
	Complex x, y;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	x.input(s1);
	y.input(s2);
	Complex z = x + y;
	cout << z << endl;
}
