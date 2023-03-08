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

/**
 * @brief
 *  用pre代表已经翻转后的最后一个节点，cur代表还未翻转的第一个节点，tmp保持不断连
 *  因为翻转后，要让第一个节点的next为null，所以pre初始为null
 */

ListNode *reverseList(ListNode *l)
{
    ListNode *cur = l->next;
    ListNode *pre = nullptr;
    while (cur)
    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
// pre cur tmp
// nul 1    2    3 4 5

void show(ListNode *l)
{
    ListNode *p = l;
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
        l = reverseList(l);
        show(l);
    }
}