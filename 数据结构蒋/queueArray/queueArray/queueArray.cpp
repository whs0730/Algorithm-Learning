// task_3.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//有*有序*数组array，要求使用队列，删除有序数组中重复出现的数组元，使每个数组元最多出现两次，输出数组的新长度和数组成员。

//输入和输出格式示例：
//输入: 
//9 1 2 2 3 3 3 4 5 6
//输出: 
//8 1 2 2 3 3 4 5 6

#include <iostream>
using namespace std;

template<class Ty>
class queue {
	Ty* q;
	int size;
	int _front, _rear;

public:
	queue(int size) {
		this->size = size;
		q = new Ty[size];
		_front = 0;
		_rear = -1;
	}
	~queue() {

	}

	bool IsEmpty()
	{
		return _rear<_front;
	}

	bool  push(int elem)
	{
		if (_rear >= size - 1) {
			return false;
		}
		q[++_rear] = elem;
		return true;
	}

	Ty front() {
		return q[_front];
	}

	void  pop()
	{
		if (!IsEmpty()) {
			_front++;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}

	int dataSize = 0;

	queue<int> q(n);    //此处创建队列对象q，下面请使用该队列对象q完成题目

	// 使用dataSize记录删除重复数据后，数组data中的数据个数。
	//请在下方编写代码
	for (int i = 0; i < n; ) {
		int current = data[i];
		int count = 0;

		while (i < n && data[i] == current) {
			count++;
			i++;
		}

		int addTimes = (count > 2) ? 2 : count;
		for (int j = 0; j < addTimes; j++) {
			q.push(current);
		}
	}
	queue<int> temp(n);  
	while (!q.IsEmpty()) {
		temp.push(q.front());
		q.pop();
		dataSize++;
	}
	for (int i = 0; i < dataSize; i++) {
		q.push(temp.front());
		data[i] = temp.front();
		temp.pop();
	}


	cout << dataSize << " ";
	for (int i = 0; i < dataSize; ++i) {
		cout << data[i] << " ";
	}
		
	return 0;
}




