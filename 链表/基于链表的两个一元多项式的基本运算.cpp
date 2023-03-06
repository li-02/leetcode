#include <iostream>
using namespace std;

struct ListNode
{
    int c;
    int index;
    ListNode *next;
    ListNode(int c, int index) : c(c), index(index) {}
};

void createList(ListNode *l, int a[], int n)
{
    ListNode *cur = l;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            ListNode *p = new ListNode(i, a[i]);
            cur->next = p;
            cur = p;
        }
    }
}
ListNode *add(ListNode *a, ListNode *b)
{
    ListNode *p1 = a->next;
    ListNode *p2 = b->next;
    while ()
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int cnt_a, cnt_b;
        cin >> cnt_a >> cnt_b;
        int a[100] = {0}, b[100] = {0};
        int c, index;
        for (int i = 0; i < cnt_a; i++)
        {
            cin >> c >> index;
            a[c] = index;
        }
        for (int j = 0; j < cnt_b; j++)
        {
            cin >> c >> index;
            b[c] = index;
        }
        ListNode *aa = new ListNode(0, 0);
        ListNode *bb = new ListNode(0, 0);
        createList(aa, a, cnt_a);
        createList(bb, b, cnt_b);
        char op;
        cin >> op;
        if (op == '+')
        {
            add(aa, bb);
        }
    }
}