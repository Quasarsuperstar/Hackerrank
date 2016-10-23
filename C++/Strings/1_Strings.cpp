

#include <iostream>
#include <string>
using namespace std;

int main() {
	string mya, myb, mya2, myb2;
	cin >> mya;
	cin >> myb;

	myb2 = myb;
	mya2 = mya;
	myb2[0] = mya[0];
	mya2[0] = myb[0];

	cout << mya.size() << " " << myb.size() << endl << mya + myb << endl << mya2 << " " << myb2 << endl;


	system("pause");
	return 0;
}