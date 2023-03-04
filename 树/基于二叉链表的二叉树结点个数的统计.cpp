#include <iostream>
using namespace std;

struct Bitree
{
    char val;
    Bitree *left, *right;
    Bitree(char val) : val(val), left(nullptr), right(nullptr) {}
};
int node0, node1, node2;

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

void countPoints(Bitree *t)
{
    if (t)
    {
        if (t->left && t->right)
            node2++;
        else if (t->left == nullptr && t->right == nullptr)
            node0++;
        else
            node1++;
        countPoints(t->left);
        countPoints(t->right);
    }
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
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "0")
            return 0;
        int i = 0;
        node0 = 0, node1 = 0, node2 = 0;
        Bitree *t = preOrderCreate(s, i);
        countPoints(t);
        cout << node0 << " " << node1 << " " << node2 << endl;
    }
    return 0;
}