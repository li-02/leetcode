#include <iostream>
using namespace std;

struct ListNode
{
    int c;
    int index;
    ListNode *next;
    ListNode(int c, int index) : c(c), index(index) {}
};
/**
 * @brief Create a List object desc orderd
 *
 * @param l
 * @param n points
 */
void createList(ListNode *l, int n)
{
    int c, index;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> index;
        ListNode *p = new ListNode(c, index);
        ListNode *pre = l;
        ListNode *cur = l->next;
        // 当前的点比最开头的点小,就一直后移
        while (cur && p->index < cur->index)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = p;
        p->next = cur;
    }
}
void show(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        if (p->index != 0)
        {
            cout << p->c << "x^" << p->index;
        }
        else
        {
            cout << p->c << endl;
        }
        if (p->next)
        {
            cout << "+";
        }
        p = p->next;
    }
}
void normalShow(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        cout << p->c << endl;
        p = p->next;
    }
}

int main()
{
    ListNode *l = new ListNode(0, 0);
    createList(l, 2);
    show(l);
}