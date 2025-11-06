/*
题目：
有*有序*数组array，要求实现一个函数，
删除有序数组中数据对象的值重复出现的数组元，
使每个数组元最多出现两次，并返回数组的新长度。
要求只能使用 O(1)的额外内存空间
（即使用额外的内存的大小是个常量，不与数组array 的长度相关）

程序输出处理后的数组元素。


输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 ...

*/


//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
using namespace std;
int removeDuplicates(int* a, int n) {
    if (n <= 2) return n;
    int j = 2;
    for (int i = 2; i < n - 1; i++) {
        if (a[i] != a[i - 2]) {
            a[j] = a[i];
            j++;
        }
    }
    return j;
    //return 数组的新长度；
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    //在本行下方编程程序代码，不要修改main()函数中本行及以上的内容
    int newLength = removeDuplicates(arr, n);
    for (int i = 0; i < newLength + 1; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;





    //代码编辑结束，不要修改本行及以下的内容
    return 0;
}