/* String3_AttributeParser.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.

We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, 
followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ... >

The closing tags follow the format:

< /tag-name >

For example:

<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>

The attributes are referenced as:

tag1~value
tag1.tag2~name

You are given the source code in HRML format consisting of N lines. You have to answer Q queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.

Input Format

The first line consists of two space separated integers, N and Q. N specifies the number of lines in the HRML source program. Q specifies the number of queries.

The following NN lines consist of either an opening tag with zero or more attributes or a closing tag.

Q queries follow. Each query consists of string that references an attribute in the source program.



Each line in the source program contains, at max, 200 characters.
Every reference to the attributes in the QQ queries contains at max 200 characters.
All tag names are unique.

Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if there is no such attribute in the source program.

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output

Name1
Not Found!
HelloWorld

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;




class tag {
private:
	bool state;
	tag * parent;
	vector<tag *> children;
public:
	string tagname;
	vector<string> attribute;
	vector<string> value;
	
	tag();

	void open();

	void close();

	bool isopen(){
		return state;
	}
	
	//tag * curstag(){
	//	return curtag;
	//}

	tag * hastag(string taggy){
		tag * temp = NULL;
		for (unsigned int i = 0; i < children.size(); i++){
			if (children[i]->tagname == taggy){
				temp = children[i];
			}
		}
		return temp;
	}

	string lookup(string atty){
		string temp = "Not Found!";
		for (unsigned int i = 0; i < value.size(); i++){
			if (attribute[i] == atty){
				temp = value[i];
			}
		}
		return temp;

	}

};

tag * curtag;

tag::tag(){
		{					// constructor
			if (curtag != NULL){
				parent = curtag;
				parent->children.push_back(this);
			}
			else
			{
				parent = this;
			}

			state = true;
			curtag = this;
		}
}

void tag::open(){
	state = true;
	curtag = this;
}

void tag::close(){
	state = false;
	if (parent == NULL){
		curtag = this;
	}
	else {
		curtag = parent;
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	string inpu;
	vector<string> inp;
	vector<string> quer;
	vector<tag *> tags;
	curtag = NULL;
	tag mainbody;

	curtag->tagname = "main";

	cin.ignore();

	for (int i = 0; i < N; i++){
		getline(cin,inpu);
		inp.push_back(inpu);
	}

	for (int i = 0; i < Q; i++){
		getline(cin, inpu);
		quer.push_back(inpu);
	}

	string * instream = NULL;
	string word;
	int attr = 0;
	bool qclose = true;
	string blubbels;
	string drogen;
	int postl;

	for (int i = 0; i < N; i++){
		char ch;
		int noa = 0;
		stringstream ss(inp[i]);
		while (ss >> ch){
			if (ch == '='){
				noa++;
			}
		}
		for (unsigned int j = 0; j < inp[i].length(); j++){
			switch (inp[i][j])
			{
			case '<':
				if (qclose){
					if (inp[i][j + 1] == '/'){
						curtag->close();
						j = inp[i].length();
					}
					else {
						tags.push_back(new tag);
						instream = &(curtag->tagname);
						curtag->attribute.resize(noa);
						curtag->value.resize(noa);
					}
					break;
				}
			case ' ':
				if (qclose){
					if (curtag->isopen() && instream != NULL){
						*instream = word;
						word.clear();
						instream = NULL;

					}
					break;
				}
			case '=':
				if (qclose){
					instream = &(curtag->attribute[attr]);
					attr++;
					if (curtag->isopen() && instream != NULL){
						*instream = word;
						word.clear();
						instream = NULL;
					}
					break;
				}
			case '"':
				qclose = !qclose;
				if (!qclose){
					drogen = inp[i].substr(j + 1, inp[i].length() - j + 1);
				//	cout << "DROGEN:" << drogen << endl;
					postl = inp[i].substr(j + 1, inp[i].length() - j + 1).find_first_of('"');
					blubbels = inp[i].substr(j + 1, postl);
				//	cout << "BLUBBELS" << blubbels << endl;
					if (postl > 0){
						word = blubbels;
						j = j + postl;

					}
					if (attr > 0){
						instream = &(curtag->value[attr - 1]);
					}
					else {
						cout << "fu!!!" << endl;
					}
					
				}
				else if (curtag->isopen() && instream != NULL){
					*instream = word;
					word.clear();
					instream = NULL;
				}
				
				break;
			case '>':
				if (qclose){
					if (curtag->isopen() && instream != NULL){
						*instream = word;
						word.clear();
						instream = NULL;
					}
					attr = 0;
				break;
				}
			default:
				if (curtag->isopen()){
					word.push_back(inp[i][j]);
				}
				break;
			} ;
		}
	}

	stringstream wort;
	string ch;
	tag * looktag;
	bool en;
	for (int i = 0; i < Q; i++){
		looktag = curtag;
		en = false;
		for (unsigned int j = 0; j < quer[i].length(); j++){
				switch (quer[i][j]){
				case '.':
					wort >> ch;
					wort.clear();
					looktag = looktag->hastag(ch);
					if (looktag == NULL){
				//		cout << "Not Found!" << endl;
						looktag = curtag;
					}
				break;
				case '~':
					wort >> ch;
					wort.clear();
					looktag = looktag->hastag(ch);
					if (looktag == NULL && looktag != curtag){
					//	cout << "Not Found!" << endl;
						looktag = curtag;
					}
					else {
						en = true;
					}
				break;
				default:
					wort << quer[i][j];
				break;
				}
			}
		wort >> ch;
		wort.clear();
		if (looktag != curtag && en){
			string output = looktag->lookup(ch);
			cout << output << endl;
		}
		else {
			cout << "Not Found!" << endl;
		}
	}

	system("pause");
	return 0;
}

