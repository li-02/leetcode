#include <iostream>
using namespace std;

struct Bitree
{
    char val;
    Bitree *left, *right;
    Bitree(char val) : val(val), left(nullptr), right(nullptr) {}
};

Bitree *preorderCreate(string s, int &i)
{
    Bitree *bt;
    if (s[i] == '0')
    {
        bt = nullptr;
    }
    else
    {
        bt = new Bitree(s[i]);
        i++;
        bt->left = preorderCreate(s, i);
        i++;
        bt->right = preorderCreate(s, i);
    }
    return bt;
}

void show(Bitree *t)
{
    if (t)
    {
        cout << t->val;
        show(t->left);
        cout << t->val;
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
        Bitree *t = preorderCreate(s, i);
        show(t);
        cout << endl;
    }
    return 0;
}