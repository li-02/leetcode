#include <iostream>
using namespace std;

struct Bitree
{
    /* data */
    char val;
    Bitree *left, *right;
    Bitree(char val) : val(val), left(nullptr), right(nullptr) {}
};

Bitree *preOrderCreate(string s, int &i)
{
    Bitree *t;
    if (s[i] == '0')
        t = nullptr;
    else
    {
        t = new Bitree(s[i]);
        t->left = preOrderCreate(s, ++i);
        t->right = preOrderCreate(s, ++i);
    }
    return t;
}

void preShow(Bitree *t)
{
    if (t)
    {
        cout << t->val;
        preShow(t->left);
        preShow(t->right);
    }
}

void inShow(Bitree *t)
{
    if (t)
    {
        inShow(t->left);
        cout << t->val;
        inShow(t->right);
    }
}

void backShow(Bitree *t)
{
    if (t)
    {
        backShow(t->left);
        backShow(t->right);
        cout << t->val;
    }
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "0")
            return 0;
        int i = 0;
        Bitree *t = preOrderCreate(s, i);
        preShow(t);
        cout << endl;
        inShow(t);
        cout << endl;
        backShow(t);
        cout << endl;
    }
    return 0;
}