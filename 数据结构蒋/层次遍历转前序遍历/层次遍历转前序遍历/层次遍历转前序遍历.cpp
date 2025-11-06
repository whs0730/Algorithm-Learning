
/*

题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为 n=2^d-1 ，
存储方式是按层次周游逐个结点顺序存入到数组A中。
请利用一个栈结构，写出算法将该二叉树的前序遍历结果存储在数组 B 中。
本题中二叉树节点中的数据用字符类型表示。

输入格式：
字符1 字符2 字符3 ... 字符n

输出格式
字符1 字符2 字符3 ... 字符n


*/

#include<iostream>
#include<stack>
using namespace std;
//递归版本
//void change(char* A, char* B, int start, int size, int& index) {
//	if (start>=size)return;
//	B[index++] = A[start];
//	int left =2*start+1;
//	int right =2*start+2;
//	change(A, B, left, size,index);
//	change(A, B, right,size,index);
//}
//栈版本
void change(char* A, stack<char> &B, int start, int size, int& index) {
	if (start>=size)return;
	B.push(A[start]);
	int left =2*start+1;
	int right =2*start+2;
	change(A, B, left, size,index);
	change(A, B, right,size,index);
}int main() {

	int n;
	std::cin >> n;  //输入数据的长度
	char* data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		std::cin >> data[i];

	//不要修改main()函数中以上部分的内容---------------------------
	stack<char>StackData;
	int index = 0;
	change(data, StackData, 0, n, index);
	char* newData = new char[n];
	for (int i =n-1; i>=0; i--) {
		newData[i] = StackData.top();
		StackData.pop();
	}
	for (int i = 0; i < n; ++i) {
		cout << newData[i];
	}




	//不要修改main()函数中以下部分的内容---------------------------

	delete[] data;
	return 0;
}


