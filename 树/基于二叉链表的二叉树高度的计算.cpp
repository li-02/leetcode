#include <iostream>
using namespace std;

struct Bitree
{
    /* data */
    char val;
    Bitree *left, *right;
    Bitree(char val) : val(val), left(nullptr), right(nullptr) {}
};
Bitree *createTree(string s, int &i)
{
    Bitree *t;
    if (s[i] == '0')
        t = nullptr;
    else
    {
        t = new Bitree(s[i]);
        t->left = createTree(s, ++i);
        t->right = createTree(s, ++i);
    }
    return t;
}

int countHeight(Bitree *t)
{
    if (!t)
        return 0;
    else
    {
        int lefth = countHeight(t->left);
        int righth = countHeight(t->right);
        return lefth > righth ? lefth + 1 : righth + 1;
    }
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "0")
            break;
        int i = 0;
        Bitree *t = createTree(s, i);
        cout << countHeight(t) << endl;
    }
    return 0;
}