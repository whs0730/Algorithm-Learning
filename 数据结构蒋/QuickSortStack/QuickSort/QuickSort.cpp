/*
题目：
使用一个栈，在函数QuickSortNonRec(int * a , int n )中，实现快速排序算法的非递归形式。
main()函数中建立测试数据，调用该函数，输出排序结果。

输入格式：
整数n(数据长度) 数值1 数值2 ... 数值n

输出格式:
数值1 数值2 ... 数值n

*/


#include <iostream>
#include<stack>
using namespace std;

void QuickSortNonRec(int* a, int n) {
	//本函数内，在本行下方编写程序代码，不要修改本行及以上的内容
	if (n <= 1) {
		return;
	}
	stack<int>Lowstack;
	stack<int>Highstack;
	Lowstack.push(0);
	Highstack.push(n - 1);
	while (!Lowstack.empty()) {
		int low = Lowstack.top();
		Lowstack.pop();
		int high = Highstack.top();
		Highstack.pop();
		if (low >= high) {
			continue;
		}
		int temp = a[low];
		int i = low;
		for (int j = i + 1; j <= high; j++) {
			if (a[j] < temp) {
				i++;
				swap(a[j], a[i]);
			}
		}
		swap(a[i], a[low]);
		int p = i;
		if (p - low > high - p) {
			Lowstack.push(low);
			Lowstack.push(p + 1);
			Highstack.push(p - 1);
			Highstack.push(high);
		}
		else {
			Lowstack.push(p+1);
			Lowstack.push(low);
			Highstack.push(high);
			Highstack.push(p-1);
		}


	}



	//本函数内，代码编辑结束，不要修改本行及以下的内容

}




//不要修改main()函数中的内容
int main()
{
	int n;
	cin >> n;

	int* data = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> data[i];

	QuickSortNonRec(data, n);

	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";

	delete[] data;
	return 0;
}