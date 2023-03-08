#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void createList(ListNode *l, int n)
{
    ListNode *cur = l;
    while (n--)
    {
        int val;
        cin >> val;
        ListNode *p = new ListNode(val);
        cur->next = p;
        cur = p;
    }
}

void divideList(ListNode *l)
{
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *p = l->next;
    while (p)
    {
        if (!p->val)
        {
            p = p->next;
        }
        else if (p->val > 0)
        {
            p1->next = p;
            p1 = p;
            p = p->next;
        }
        else
        {
            p2->next = p;
            p2 = p;
            p = p->next;
        }
    }
    p1->next = nullptr;
    p2->next = nullptr;
    p1 = l1->next;
    p2 = l2->next;
    while (p2)
    {
        cout << p2->val;
        if (p2->next)
            cout << " ";
        p2 = p2->next;
    }
    cout << endl;
    while (p1)
    {
        cout << p1->val;
        if (p1->next)
            cout << " ";
        p1 = p1->next;
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
        ListNode *l = new ListNode(0);
        createList(l, n);
        divideList(l);
    }
}
