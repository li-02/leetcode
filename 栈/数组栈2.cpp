#include <iostream>
using namespace std;
#define maxsize 100
struct Stack
{
    /* data */
    int *top;
    int *base;
    int size;
};

void init(Stack &s)
{
    s.base = new int[maxsize];
    s.top = s.base;
    s.size = maxsize;
}

int push(Stack &s, int e)
{
    if (s.top - s.base == s.size)
        return -1;
    *s.top = e;
    s.top++;
    return 0;
}

bool empty(Stack s)
{
    if (s.top == s.base)
        return true;
    else
        return false;
}

int pop(Stack &s)
{
    if (empty(s))
        return -1;
    else
    {
        s.top--;
        return *s.top;
    }
}

int top(Stack &s)
{
    if (empty(s))
        return -1;
    return *(s.top - 1);
}