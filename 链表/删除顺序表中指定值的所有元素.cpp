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

void deleteT(ListNode *l, int t)
{
    ListNode *pre = l;
    ListNode *p = l->next;
    while (p)
    {
        if (p->val == t)
        {
            pre->next = p->next;
            p = p->next;
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }
}
void show(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        cout << p->val;
        if (p->next)
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
        ListNode *l = new ListNode(0);
        createList(l, n);
        int target;
        cin >> target;
        deleteT(l, target);
        show(l);
    }
}