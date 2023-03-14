#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void createList(ListNode *&l, int n)
{
    ListNode *cur = l;
    int val;
    while (n--)
    {
        cin >> val;
        ListNode *p = new ListNode(val);
        cur->next = p;
        cur = p;
    }
}

int avg(ListNode *l)
{
    ListNode *cur = l;
    if (cur->next == nullptr)
        return cur->val;
    else
    {
        return cur->val + avg(cur->next);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        int val;
        ListNode *l = new ListNode(0);
        createList(l, n);
        double sum = double(avg(l));
        // 输出小数，控制位数
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << sum / n << endl;
    }
}