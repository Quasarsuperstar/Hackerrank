#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated, BoxesDestroyed;// , newboxes, copiedboxes, definedboxes;


class Box {
private:
	long l;
	long b;
	long h;
public:
	Box(){
		l = 0;
		b = 0;
		h = 0;
		BoxesCreated++;
	//	newboxes++;
	}
	Box(int length, int breadth, int height){
		l = length;
		b = breadth;
		h = height;
		BoxesCreated++;
	//	definedboxes++;
	}
	Box(Box& B){
		l = B.l;
		b = B.b;
		h = B.h;
		BoxesCreated++;
	//	copiedboxes++;
	}
	~Box(){
		BoxesDestroyed++;
	}
	int getLength(){
		return l;
	} // Return box's length
	
	int getBreadth(){
		return b;
	}// Return box's breadth

	int getHeight(){
		return h;
	}//Return box's height
	 
	long long CalculateVolume(){
		return (long long)l*(long long)b*(long long)h;
	}// Return the volume of the box
	bool operator<(Box &B){
		bool temp;
		temp = (l < B.l) || (b < B.b && l == B.l) || (h < B.h && b == B.b && l == B.l);
		return temp;
	}
	friend ostream& operator<< (ostream& out, Box arg1);

};


ostream& operator<< (ostream& out, Box arg1){
	out << arg1.l << " " << arg1.b << " " << arg1.h;
	return out;
}



//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }



//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i<n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser" << endl;
			}
			else
			{
				cout << "Greater" << endl;
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	BoxesCreated = 0;
	BoxesDestroyed = 0;
//	newboxes = 0;
//	definedboxes = 0;
//	copiedboxes = 0;

	check2();
	cout << "Boxes Created : " << BoxesCreated << endl << "Boxes Destroyed : " << BoxesDestroyed << endl;
//	cout << "New Boxes Created : " << newboxes << endl << "Boxes defined : " << definedboxes << endl << "Boxes copied : " << copiedboxes << endl;
	system("pause");
}
