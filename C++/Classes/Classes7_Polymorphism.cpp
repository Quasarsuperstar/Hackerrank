#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val){};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val){};
};

class Cache{

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};
/****************************CODE HERE***********************************/

class LRUCache : public Cache {
public:
	LRUCache(){
		cp = 0;
	}
	LRUCache(int c){
		cp = c;
		Node * temp = new Node(-1,-1);
		head = temp;
		for (int i = 0; i < cp; i++) {
			temp->next = new Node(temp,NULL,-1, -1);
			temp = temp->next;
		}
		tail = temp;
		tail->next = NULL;
		head->prev = NULL;
	}
	void set (int key, int value){
		if (get(key) == -1){
			Node * temp = new Node(NULL,head,key,value);
			head->prev = temp;
			tail = tail->prev;
			tail->next = NULL;
			head = temp;
			head->prev = NULL;
		}
		else {
			head->value = value;
		}
	}
	int get (int key) {
		Node * temp = head;
		for (int i = 0; i < cp; i++){
			if (temp->key == key){
				movetofront(temp);
				return head->value;
			}
			else temp = temp->next;
		}
		return -1;
	}
	void movetofront(Node * nade){
		if (nade == head){
			return;
		}
		if (nade->next){
			nade->next->prev = nade->prev;
		}
		else { 
			tail = nade;
			tail->next = NULL;
		}
		nade->prev->next = nade->next;
		nade->next = head;
		nade->prev = NULL;
		head->prev = nade;
		head = nade;

	}
};


/****************************CODE HERE***********************************/
int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i<n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	system("pause");
	return 0;
}
