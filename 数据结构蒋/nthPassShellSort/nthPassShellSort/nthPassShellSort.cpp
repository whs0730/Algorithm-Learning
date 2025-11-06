/*
题目：
给出一组排序关键字序列，写一个函数 nthPassShellSort，
对序列从第n-1趟排序完毕状态开始，进行到第n趟Shell排序
( 初始状态为第`0`趟，采用`Hibbard`增量序列，即1, 3, 7, ... ,  2^k-1  )。

在shellSort()函数中，反复调用该函数，实现shellsort算法，
在此过程中，逐次输出每一趟排序结果。

main()函数中建立测试数据，调用shellSort()函数对测试数据进行排序。

输入格式：
整数n(数据长度) 数值1 数值2 ... 数值n

输出格式:
数值1 数值2 ... 数值n
数值1 数值2 ... 数值n
......
数值1 数值2 ... 数值n
(根据测试数据长度，需要进行多少趟处理，就输出多少行)
*/
#include <iostream>
using namespace std;
void nthPassShellSort(int* a, int len, int nth){
	//本函数内，在本行下方编写程序代码，不要修改本行及以上的内容
	int gap = (1<<nth) - 1;
	//在本行下方编写程序代码，不要修改本行及以上的内容
	for (int i = gap; i < len; i++) {
		int temp = a[i];
		int j;
		for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
			a[j] = a[j - gap];
		}
		a[j] = temp;
	}
	//本函数内，代码编辑结束，不要修改本行及以下的内容
}

void shellSort(int* a, int n)
{
	//本函数内，在本行下方编写程序代码，不要修改本行及以上的内容
	int k = 1;
	while ((1<<k) - 1 < n) {
		k++;
	}
	k--;
	for (int i = k; i >= 1; --i) {
		nthPassShellSort(a, n, i);
		for (int j = 0; j < n; ++j) {
			cout << a[j]<<" ";
		}
		cout << endl;
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

	shellSort(data, n);

	delete[] data;
	return 0;
}