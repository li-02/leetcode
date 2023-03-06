#include <iostream>
using namespace std;

struct Bitree
{
    /* data */
    char val;
    Bitree *left;
    Bitree *right;
    Bitree(char val) : val(val), left(nullptr), right(nullptr) {}
};

Bitree *createTree(string s, int &i)
{
    Bitree *t;
    if (s[i] == '#' || s[i] == '\0')
        t = nullptr;
    else
    {
        t = new Bitree(s[i]);
        t->left = createTree(s, ++i);
        t->right = createTree(s, ++i);
    }
    return t;
}
/**
 * @brief 叶子结点为终点,以及超过小于前一个值或大于后一个值的节点也是终点
 * 判断范围是,左子树比根节点小,即根节点递归到左子节点时,左子节点的最大值就是根节点-1,右子节点同理
 * 利用的原理就是 二叉排序树中序遍历是有序的
 * @param t
 * @param minVal
 * @param maxVal
 * @return true
 * @return false
 */
bool isBST(Bitree *t, char minVal, char maxVal)
{
    if (t == nullptr)
        return true;
    if (t->val < minVal || t->val > maxVal)
        return false;
    return isBST(t->left, minVal, t->val - 1) && isBST(t->right, t->val + 1, maxVal);
}
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        int i = 0;
        Bitree *t = createTree(s, i);
        if (isBST(t, 'a', 'z'))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
