#include <iostream>
using namespace std;
#define maxsize 100
struct Stack
{
    int data[maxsize];
    int top;
};

// 创建栈
void create(Stack &s)
{
    s.top = -1;
}
// 判空
bool isEmpty(Stack s)
{
    return s.top == -1 ? true : false;
}

// 判满
bool isFull(Stack s)
{
    return s.top >= maxsize - 1 ? true : false;
}
// 入栈
bool push(Stack &s, int x)
{
    if (isFull(s))
        return false;
    else
        s.data[++s.top] = x;
    return true;
}
// 出栈
bool pop(Stack &s, int &x)
{
    if (isEmpty(s))
        return false;
    else
        x = s.data[s.top--];
    return true;
}