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

int getMax(ListNode *l)
{
    ListNode *cur = l;
    ListNode *p = l->next;
    int maxx = 1 << 31;
    while (p)
    {
        if (p->val > maxx)
        {
            maxx = p->val;
        }
        p = p->next;
    }
    return maxx;
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
        cout << getMax(l) << endl;
    }
}