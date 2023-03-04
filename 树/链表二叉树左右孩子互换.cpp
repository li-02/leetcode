#include <iostream>
using namespace std;

struct BiTree
{
    char val;
    BiTree *left, *right;
    BiTree(char val) : val(val), left(nullptr), right(nullptr) {}
};

BiTree *orderCreateTree(string s, int &i)
{
    BiTree *bt;
    if (s[i] == '0')
    {
        bt = nullptr;
    }
    else
    {
        bt = new BiTree(s[i]);
        i++;
        bt->left = orderCreateTree(s, i);
        i++;
        bt->right = orderCreateTree(s, i);
    }
    return bt;
}

void swaplr(BiTree *&t)
{
    if (t && (t->left || t->right))
    {
        BiTree *tmp = new BiTree('0');
        tmp = t->left;
        t->left = t->right;
        t->right = tmp;
        swaplr(t->left);
        swaplr(t->right);
    }
}

void show(BiTree *t)
{
    if (t)
    {
        cout << t->val;
        show(t->left);
        show(t->right);
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
        BiTree *bt = orderCreateTree(s, i);
        swaplr(bt);
        show(bt);
        cout << endl;
    }
    return 0;
}