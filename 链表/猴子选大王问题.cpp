#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};
void createList(ListNode *&l, int n)
{
    int val;
    ListNode *cur = l;
    for (int i = 2; i <= n; i++)
    {
        ListNode *p = new ListNode(i);
        cur->next = p;
        cur = p;
    }
    cur->next = l;
    l = cur; // 指向尾结点，当要删除第一个节点的时候正好删除首节点
}

void showM(ListNode *l, int n)
{
    while (l->next != l)
    {
        for (int i = 1; i < n; i++)
        {
            l = l->next;
        }
        // t是要删除的点
        ListNode *t = l->next;
        cout << t->val << " ";
        l->next = t->next;
        delete (t);
    }
    cout << l->val << endl;
}

void show(ListNode *l)
{
    ListNode *p = l;
    cout << p->val << " ";
    p = p->next;
    while (p != l)
    {
        cout << p->val << " ";
        p = p->next;
    }
}
int main()
{
    int n, pos;
    while (cin >> n >> pos)
    {
        if (!n && !pos)
            break;
        ListNode *l = new ListNode(1);
        createList(l, n);
        showM(l, pos);
        // show(l);
    }
}