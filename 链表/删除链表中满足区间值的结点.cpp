#include <iostream>
using namespace std;

// 常用最大值 0x7fffffff
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

void deleteVal(ListNode *l, int minn, int maxx)
{
    ListNode *p = new ListNode(0);
    p = l->next;
    ListNode *pre = l;
    while (p)
    {
        if (p->val >= minn && p->val <= maxx)
        {
            pre->next = p->next;
            p = p->next;
        }
        else
        {
            pre = p;
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
        int minn, maxx;
        cin >> minn >> maxx;
        deleteVal(l, minn, maxx);
        show(l);
    }
}