/**
 * @file 基于链表的两个非递减有序序列的合并.cpp
 * @author your name (you@domain.com)
 * @brief 这个和递增的没有多大区别，建立链表的时候头插法就行
 * @version 0.1
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */
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
    ListNode *cur = l->next;
    ListNode *pre = l;
    while (n--)
    {
        int val;
        cin >> val;
        ListNode *p = new ListNode(val);
        p->next = cur;
        pre->next = p;
        cur = p;
    }
}

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;
    ListNode *cur = l1;
    while (p1 && p2)
    {
        if (p1->val > p2->val)
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
        }
        else
        {
            cur->next = p2;
            cur = p2;
            p2 = p2->next;
        }
    }
    cur->next = p1 ? p1 : p2;
    return l1;
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
    return 0;
}