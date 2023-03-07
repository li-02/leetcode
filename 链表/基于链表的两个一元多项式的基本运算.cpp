#include <iostream>
using namespace std;

struct ListNode
{
    int c;
    int index;
    ListNode *next;
    ListNode(int c, int index) : c(c), index(index), next(nullptr) {}
};

void show(ListNode *l)
{
    ListNode *p = l->next;
    if (!p)
    {
        cout << 0 << endl;
        return;
    }
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
ListNode *add(ListNode *a, ListNode *b)
{
    ListNode *p1 = a->next;
    ListNode *p2 = b->next;
    ListNode *l3 = new ListNode(0, 0);
    // 这里l3只有头结点,next是空的,不能*p3=l3->next!!!
    ListNode *p3 = l3;
    while (p1 && p2)
    {
        if (p1->index == p2->index)
        {

            int sum = p1->c + p2->c;
            if (sum)
            {
                p3->next = p1;
                p3 = p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->index > p2->index)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    return l3;
}

void sub(ListNode *a, ListNode *b)
{
    ListNode *p = b->next;
    while (p)
    {
        p->c *= -1;
        p = p->next;
    }
    show(add(a, b));
}

ListNode *mul(ListNode *a, ListNode *b)
{

    ListNode *p1 = a->next;
    ListNode *p2 = b->next;
    ListNode *L3 = new ListNode(0, 0);   // 目标多项式
    ListNode *temp = new ListNode(0, 0); // 记中间结果
    while (p1)
    {
        while (p2)
        {
            ListNode *t = new ListNode(0, 0);
            t->c = p1->c * p2->c;
            t->index = p1->index + p2->index;
            temp->next = t;
            L3 = add(L3, temp);
            p2 = p2->next;
        }
        p2 = b->next;
        p1 = p1->next;
    }
    return L3;
}

void diff(ListNode *L)
{
    ListNode *p = L->next;
    ListNode *r = NULL;
    while (p)
    {
        p->c *= p->index;
        p->index--;
        if (p->index < 0)
        {
            r = p;
            p = p->next;
            delete r;
        }
        else
        {
            p = p->next;
        }
    }
    show(L);
}

void normalShow(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        cout << p->c << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int cnt_a, cnt_b;
        cin >> cnt_a >> cnt_b;
        ListNode *a = new ListNode(0, 0);
        ListNode *b = new ListNode(0, 0);
        createList(a, cnt_a);
        createList(b, cnt_b);
        string op;
        cin >> op;
        if (op == "+")
        {
            ListNode *l = add(a, b);
            show(l);
        }
        else if (op == "-")
        {
            sub(a, b);
        }
        else if (op == "*")
        {
            ListNode *l = mul(a, b);
            show(l);
        }
        else
        {
            diff(a);
            diff(b);
        }
    }
    return 0;
}