#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void createList(ListNode *l, int n)
{
    int val;
    ListNode *cur = l;
    while (n--)
    {
        cin >> val;
        ListNode *p = new ListNode(val);
        cur->next = p;
        cur = p;
    }
}

ListNode *getIntersection(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;
    ListNode *cur = l1;
    while (p1 && p2)
    {
        if (p1->val == p2->val)
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->val > p2->val)
        {
            p2 = p2->next;
        }
        else
        {
            p1 = p1->next;
        }
    }
    // 只要求相交，所以求完将尾指针封死
    cur->next = nullptr;
    return l1;
}

void show(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        cout << p->val;
        if (p->next)
        {
            cout << " ";
        }
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        createList(l1, n);
        createList(l2, m);
        show(getIntersection(l1, l2));
    }
    return 0;
}