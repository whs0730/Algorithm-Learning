/*
---------------题目描述开始---------------
题目：
利用一个栈计算并输出Fibonacci数列的前n项。
Fibonacci数列：F[n] = F[n-1] + F[n-2](n>=2, F[0]=0, F[1]=1

输入格式：
数据n

输出格式
数据1 数据2 ... 数据n

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
#include<stack>
using namespace std;
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {

    //--------------在本行下方编程程序代码，不要修改main()函数中本行及以上的内容----------------------
    int n;
    cin >> n;
    stack<int> ST;
    while (n) {
        ST.push(n - 1);
        n--;
    }
    while (!ST.empty()) {
        cout << fibonacci(ST.top()) << " ";
        ST.pop();
    }



    //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}



