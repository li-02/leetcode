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

ListNode *getDiff(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;
    ListNode *cur = l1;
    while (p1 && p2)
    {
        if (p1->val == p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->val > p2->val)
        {
            p2 = p2->next;
        }
        else
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
        }
    }
    cur->next = p1;
    return l1;
}

int show(ListNode *l)
{
    int cnt = 0;
    ListNode *p = l->next;
    while (p)
    {
        cout << p->val;
        cnt++;
        if (p->next)
        {
            cout << " ";
        }
        p = p->next;
    }
    cout << endl;
    return cnt;
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
        int cnt = show(getDiff(l1, l2));
        cout << cnt << endl;
    }
    return 0;
}