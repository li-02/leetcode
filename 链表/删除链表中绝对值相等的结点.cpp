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
/**
 * @brief 能用map绝不用数组，奈何不让用
 *
 * @param l
 */
void deleteSame(ListNode *l)
{
    int f[1000] = {0};
    ListNode *p = l->next;
    ListNode *pre = l;
    while (p)
    {
        if (f[abs(p->val)] != 0)
        {
            pre->next = p->next;
            p = p->next;
        }
        else
        {
            f[abs(p->val)] = 1;
            p = p->next;
            pre = pre->next;
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
        deleteSame(l);
        show(l);
    }
}