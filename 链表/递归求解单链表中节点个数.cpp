#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int cal(ListNode *head)
{
    if (head->next == nullptr)
        return 1;
    else
    {
        return 1 + cal(head->next);
    }
}
void show(ListNode *f)
{
    while (f)
    {
        cout << f->val << endl;
        f = f->next;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (n--)
        {
            int val;
            cin >> val;
            ListNode *p = new ListNode(val);
            cur->next = p;
            cur = p;
        }
        cout << cal(head->next) << endl;
    }
    return 0;
}
