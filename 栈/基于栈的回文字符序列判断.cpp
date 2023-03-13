#include <iostream>
using namespace std;

struct Stack
{
    /* data */
    char data[100];
    int top;
};

void init(Stack &s)
{
    s.top = -1;
}
void push(Stack &s, char i)
{
    s.data[++s.top] = i;
}
void pop(Stack &s)
{
    s.top--;
}
char top(Stack s)
{
    return s.data[s.top];
}
bool empty(Stack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
}
int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "0")
            break;
        Stack s;
        init(s);
        for (int i = 0; i < str.size() / 2; i++)
        {
            push(s, str[i]);
        }
        int pos = str.size() % 2 == 0 ? str.size() / 2 : str.size() / 2 + 1;
        int flag = 1;
        for (int i = pos; i < str.size(); i++)
        {
            if (top(s) == str[i])
            {
                pop(s);
            }
            else
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
    }
}