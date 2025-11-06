/*
---------------题目描述开始---------------
题目：
利用栈将一个中缀表达式转换为后缀表达式，并计算该后缀表达式的值
实现函数void PostExp(const string& expstr, string& pexpstr)
将字符串expstr中的中缀表达式，转换为后缀表达式，放入字符串pexpstr中


本题可以使用STL中的stack容器类

输入格式：
中缀表达式字符序列

输出格式
后缀表达式字符序列
数据1

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}
int number(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else
    {
        return 0;
    }
}
void PostExp(const string& expstr, string& pexpstr)
{
    stack<char>Stack;
    pexpstr.clear();
    for (char c : expstr) {
        if (is_digit(c)) {
            pexpstr += c;
        }
        else if (c == '(') {
            Stack.push(c);
        }
        else if (c == ')') {
            while (!Stack.empty()&& Stack.top() != '(') {
                pexpstr += Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
        else {
            while (!Stack.empty() && number(c) <= number(Stack.top())) {
                pexpstr += Stack.top();
                Stack.pop();
            }
            Stack.push(c);
        }
    }
    while (!Stack.empty()) {
        pexpstr += Stack.top();
        Stack.pop();
    }
}

int calc(const string& pexpstr) {
    stack<int> newStack;
    for (char c : pexpstr) {
        if (is_digit(c)) {
            newStack.push(c - '0');
        }
        else
        {
            int num2 = newStack.top();
            newStack.pop();
            int num1 = newStack.top();
            newStack.pop();

            switch (c) {
            case '+': newStack.push(num1 + num2); break;
            case '-': newStack.push(num1 - num2); break;
            case '*': newStack.push(num1 * num2); break;
            case '/': newStack.push(num1 / num2); break;
            }
        }
    }
    return newStack.top();
}

int main() {

    //--------------不要修改main()函数中的内容----------------------

    string exp, pexp;

    cin >> exp;

    PostExp(exp, pexp);

    cout << pexp << endl;

    cout << calc(pexp);

    //-------------------------------------------------------------
    return 0;
}



