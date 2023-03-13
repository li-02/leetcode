#include <iostream>
using namespace std;

/**
 * @brief 双向循环链表
 *
 */
struct DoubleList
{
    /* data */
    int val;
    DoubleList *next;
    DoubleList *pre;
    DoubleList(int val) : val(val), next(nullptr), pre(nullptr) {}
};

void createList(DoubleList *l, int n)
{
    int val;
    DoubleList *end = l;
    DoubleList *head = l;
    while (n--)
    {
        cin >> val;
        DoubleList *p = new DoubleList(val);
        p->pre = end;
        p->next = head;
        end->next = p;
        head->pre = p;
        end = p;
    }
}

void changePos(DoubleList *l, int pos)
{
    DoubleList *p = l;
    while (pos--)
    {
        p = p->next;
    }
    DoubleList *pre = p->pre;
    // 只有一个节点
    if (pre == p->next)
        return;
    DoubleList *prepre = p->pre->pre;
    DoubleList *next = p->next;
    prepre->next = p;
    pre->next = next;
    pre->pre = p;
    p->pre = prepre;
    p->next = pre;
    next->pre = pre;
}
void show(DoubleList *l)
{
    DoubleList *p = l->next;
    while (p && p != l)
    {
        cout << p->val;
        if (p->next != l)
            cout << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        DoubleList *l = new DoubleList(0);
        l->pre = l->next = l;
        createList(l, n);
        int pos;
        cin >> pos;
        changePos(l, pos);
        show(l);
    }
}
