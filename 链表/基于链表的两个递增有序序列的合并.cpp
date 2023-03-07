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
    ListNode *cur = l;
    while (n--)
    {
        int num;
        cin >> num;
        ListNode *p = new ListNode(num);
        cur->next = p;
        cur = p;
    }
}

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1->next;
    ListNode *cur = l1;
    ListNode *p2 = l2->next;
    while (p1 && p2)
    {
        if (p1->val > p2->val)
        {
            cur->next = p2;
            cur = p2;
            p2 = p2->next;
        }
        else if (p1->val < p2->val)
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
        }
        else
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    cur->next = p1 ? p1 : p2;
    return l1;
}
/**
 * @brief oj 对空格也有要求
 *
 * @param l
 */
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
        createList(l1, n);
        ListNode *l2 = new ListNode(0);
        createList(l2, m);
        ListNode *l3 = mergeList(l1, l2);
        show(l3);
    }
}