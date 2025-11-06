
/*

题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为 2^d-1 ，
存储方式是按中序逐个将结点顺序存入到数组A中。
请写出递归算法将该二叉树的前序遍历结果存储在数组 B 中。


输入格式：
字符1 字符2 字符3 ... 字符n

输出格式
字符1 字符2 字符3 ... 字符n


*/

#include<iostream>
using namespace std;
void change(char* A,char*B, int left, int right, int&index) {
    int mid = (left + right) / 2;
    int count = 0;
    if (left > right) {
        return;
    }
    if (right >= left) {
        B[index++] = A[mid];
    }
    change(A, B, left, mid - 1, index);
    change(A, B, mid + 1, right, index);
    
}

int main() {

    int n;
    std::cin >> n;  //输入数据的长度
    char* data = new char[n];

    for (int i = 0; i < n; ++i) //输入n个数据
        cin >> data[i];
    //不要修改main()函数中以上部分的内容---------------------------
    char* newData = new char[n];
    int index = 0;
    change(data, newData, 0, n, index);
    for (int i = 0; i < n; ++i) {
        cout << newData[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    delete[]newData;



    //不要修改main()函数中以下部分的内容---------------------------

    delete[] data;
    return 0;
}


