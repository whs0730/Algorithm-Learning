#include<iostream>
using namespace std;
class IntSLLNode {
public:
	int info;
	IntSLLNode* next;
	IntSLLNode() {
		next = nullptr;
	}
	IntSLLNode(int el, IntSLLNode *ptr=nullptr):info(el), next(ptr){}
};
class IntSLLList {
private:
	IntSLLNode* head, *tail;
public:
	IntSLLList() {
		head = tail = 0;
	}
	int isEmpty() {
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	void display();
	bool isInList(int)const;
};
void 	IntSLLList::addToHead(int info) {
	head= new IntSLLNode(info,head);
	if (tail == 0) {
		tail = head;
	}
}
void IntSLLList::addToTail(int info) {
	if (tail != 0) {
		tail->next = new IntSLLNode(info);
		tail = tail->next;
	}
	else {
		head = tail = new IntSLLNode(info);
	}
}
int IntSLLList::deleteFromHead() {
	int data = head->info;
	IntSLLNode* temp = head;
	if (head == tail) {
		head = tail = 0;
	}
	else {
		head = head->next;
	}
	delete temp;
	return data;
}
int IntSLLList::deleteFromTail() {
	int data = tail->info;
	if (head == tail) {
		delete head;
		head = tail = 0;
	}
	else
	{
		IntSLLNode* temp;
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}
	return data;
}
void IntSLLList::deleteNode(int data) {
	if (head != 0) {
		if (head == tail && head->info == data) {
			delete head;
			head = tail = 0;
		}
		else if (data == head->info) {
			IntSLLNode* temp = head;
			temp = head->next;
			delete head;
			head = temp;
		}
		else
		{
			IntSLLNode* temp;
			for (temp = head; temp != 0 && !(temp->next->info = data); temp = temp->next);
			if (temp->next != nullptr) {
				temp->next = temp->next->next;
				if (temp->next == tail) {
					tail = temp;
				}
				delete temp->next;
			}
		}
	}
}
void IntSLLList::display() {
	IntSLLNode* temp = head;
	while (temp!= 0) {
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << endl;
}
bool IntSLLList::isInList(int data)const {
	IntSLLNode* temp;
	for (temp = head; temp != 0 && !(temp->info == data); temp = temp->next);
	return temp != 0;
}
int main() {
	IntSLLList list;
	//从头部添加
	cout << "please enter the count n:" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v1;
		cout << "please enter v1:" << endl;
		cin >> v1;
		list.addToHead(v1);
	}
	cout << "display the list:" << endl;
	list.display();
	cout << endl;
	//从尾部添加
	cout << "please enter the count m:" << endl;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int v2;
		cout << "please enter v1:" << endl;
		cin >> v2;
		list.addToTail(v2);
	}
	cout << "display the list:" << endl;
	list.display();
	//从头部删除
	list.deleteFromHead();
	list.display();
	//从尾部删除
	list.deleteFromTail();
	list.display();
	//删除特定值
	cout << "enter the num you want delete:" << endl;
	int a;
	cin >> a;
	cout << endl;
	list.deleteNode(a);
	list.display();
	cout << "enter the num you want delete:" << endl;
	int b;
	cin >> b;
	cout << endl;
	list.deleteNode(b);
	list.display();
	//是否存在
	cout << "enter the num you want to know whether it is in list:" << endl;
	int c;
	cin >> c;
	cout << endl;
	cout<<list.isInList(c);
	return 0;
}