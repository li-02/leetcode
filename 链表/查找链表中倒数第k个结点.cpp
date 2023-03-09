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
int searchPos(ListNode *l, int pos)
{
    ListNode *low = l;
    ListNode *fast = l;
    while (pos--)
    {
        fast = fast->next;
    }
    while (fast)
    {
        low = low->next;
        fast = fast->next;
    }
    return low->val;
}
// head 1 2

int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        ListNode *l = new ListNode(0);
        createList(l, n);
        int pos;
        cin >> pos;
        cout << searchPos(l, pos) << endl;
    }
}