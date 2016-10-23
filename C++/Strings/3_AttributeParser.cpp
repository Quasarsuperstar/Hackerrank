
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {

	int n, q, i;
	cin >> n >> q;
	string temp;
	vector<string> hrml;
	vector<string> quer;
	cin.ignore();

	for (i = 0; i<n; i++){
		getline(cin, temp);
		hrml.push_back(temp);
	}
	for (i = 0; i<q; i++){
		getline(cin, temp);
		quer.push_back(temp);
	}

	map<string, string> m;
	vector<string> tag;

	for (i = 0; i<n; i++){
		temp = hrml[i];
		temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
		temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

		if (temp.substr(0, 2) == "</"){
			tag.pop_back();
			//cout<<"\nempty";
		}
		else{
			//cout<<<<endl;
			stringstream ss;
			ss.str("");
			//ss<<(temp.substr(0,temp.size()-2));
			ss << temp;
			string t1, p1, v1;
			char ch;
			ss >> ch >> t1 >> p1 >> ch >> v1;
			//size_t = v1.find("")
			//cout<<"t1: "<<t1<<" p1: "<<p1<<" v1: "<<v1<<endl;
			string temp1 = "";
			if (tag.size()>0){
				temp1 = *tag.rbegin();
				temp1 = temp1 + "." + t1;
			}
			else
				temp1 = t1;
			tag.push_back(temp1);
			m[*tag.rbegin() + "~" + p1] = v1;
			//cout<<"Tag: "<<*tag.rbegin()<<endl;
			while (ss){
				ss >> p1 >> ch >> v1;
				m[*tag.rbegin() + "~" + p1] = v1;
			}
		}

	}



	for (i = 0; i<q; i++){
		if (m.find(quer[i]) == m.end())
			cout << "Not Found!\n";
		else
			cout << m[quer[i]] << endl;
	}

	system("pause");
	return 0;

}
