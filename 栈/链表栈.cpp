#include <iostream>
using namespace std;

struct Stack
{
    /* data */
    int data;
    Stack *next;
    Stack(int data) : data(data), next(nullptr) {}
};

void push(Stack *&s, int val)
{
    Stack *p = new Stack(val);
    p->next = s;
    s = p;
}

void pop(Stack *&s)
{
    Stack *p = s;
    s = s->next;
    delete p;
}

bool empty(Stack *s)
{
    return s == nullptr ? true : false;
}

int top(Stack *s)
{
    return s->data;
}
void show(Stack *s)
{
    while (s->next)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
int main()
{
    Stack *s = new Stack(0);
    push(s, 1);
    push(s, 2);
    cout << top(s) << endl;
    show(s);
    pop(s);
    show(s);
}
