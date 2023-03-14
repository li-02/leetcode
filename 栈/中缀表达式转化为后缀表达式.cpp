/**
 *
 *
1、任何中缀表达式都由运算数，运算符，括号（大，中，小），这三部分组成。
2、从中缀表达式的左边开始扫描（脑中自己想像的），若遇到运算数时，则直接将其输出（不压入堆栈）。
3、若遇到左括号，则将其压栈。
4、若遇到右括号，表达括号内的中缀表达式已经扫描完毕。这时需将栈顶的运算符依次弹出并输出，直至遇到左括号[左括号弹出但不输出]。
5、若遇到的是运算符：
    a、如果该运算符的优先级大于栈顶运算符的优先级时，将其压栈
    b、如果该运算符的优先级小于栈顶运算符的优先级时，将栈顶运算符弹出并输出，接着和新的栈顶运算 符比较，
       若大于，则将其压栈，
       若小于，继续将栈顶运算符弹出并输出......(一直递归下去，直至运算符大于栈顶云算符为止)。

6、最后一步，若扫描到中缀表达式的末尾[即扫描结束]，若堆栈中还有存留的运算符依次弹出并输出即可。
 */
/*
中缀转后缀C++代码实现(比较方便)
1.遇到操作数：添加到后缀表达式中或直接输出
2.栈空时：遇到运算符，直接入栈
3.遇到左括号：将其入栈
4.遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
注意：左括号不输出到后缀表达式
5.遇到其他运算符：弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈
6.将栈中剩余内容依次弹出后缀表达式
*/

#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cstdio>
#define MAX 100
using namespace std;

// 设置优先级(注意默认操作数的优先级最高，即其不需要进栈，进栈的都是运算符)
map<char, int> p;

// 一些初始化
struct Node
{
    double num; // 操作数
    char op;    // 操作符
    bool flag;  // true表示操作数，false表示操作符
};
typedef struct Node node;

stack<node> s; // 操作符栈
queue<node> q; // 后缀表达式队列

//******************************************************
void change(string str)
{
    node temp;
    for (int i = 0; i < str.length();)
    {
        if (str[i] == '(')
        { // 3.遇到左括号：将其入栈
            temp.flag = false;
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else if (str[i] == ')')
        { // 4.遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
            while (!s.empty() && s.top().op != '(')
            {
                q.push(s.top());
                s.pop();
            }
            s.pop(); // 弹出左括号
            i++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            // 如果是数字
            temp.flag = true;
            temp.num = str[i] - '0';
            i++; // 后移一位,因为数字不一定是个位数
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp); // 操作数进入后缀表达式
        }
        else
        {
            // 如果是操作符
            // 5.遇到其他运算符：弹出所有优先加大于或等于该运算符的栈顶元素，然后将该运算符入栈
            temp.flag = false;
            while (!s.empty() && p[s.top().op] >= p[str[i]])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    // 6.将栈中剩余内容依次弹出后缀表达式
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    node cur;
    string str;
    p['+'] = p['-'] = 1; // 通过hashmap赋值
    p['*'] = p['/'] = 2;
    cin >> str;
    change(str);
    while (!q.empty())
    {
        cur = q.front();
        if (cur.flag == true)
            cout << cur.num << " ";
        else
            cout << cur.op << " ";
        q.pop();
    }

    return 0;
}