#include <iostream>
using namespace std;

struct BiTree
{
    char val;
    BiTree *left, *right;
    BiTree(char val) : val(val), left(nullptr), right(nullptr) {}
};

BiTree *preOrderCreate(string s, int &i)
{
    BiTree *btree;
    if (s[i] == '0')
        btree = nullptr;
    else
    {
        btree = new BiTree(s[i]);
        i++;
        btree->left = preOrderCreate(s, i);
        i++;
        btree->right = preOrderCreate(s, i);
    }
    return btree;
}

void show(BiTree *bt)
{
    if (bt)
    {
        cout << bt->val;
        show(bt->left);
        show(bt->right);
    }
}
int cmp(BiTree *A, BiTree *B)
{
    if (A && B)
    {
        if (A->val != B->val)
        {
            return 0;
        }
        cmp(A->left, B->left);
        cmp(A->right, B->right);
    }
}
int main()
{
    string a, b;
    while (cin >> a)
    {
        if (a == "0")
            return 0;
        cin >> b;
        int i = 0;
        BiTree *A = preOrderCreate(a, i);
        i = 0;
        BiTree *B = preOrderCreate(b, i);
        if (cmp(A, B) == 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }
}