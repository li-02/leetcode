#include <iostream>
using namespace std;

struct ListNode
{
    string no;
    string name;
    string price;
    ListNode *next;
    ListNode(string no, string name, string price) : no(no), name(name), price(price) {}
};

void deleteEqual(ListNode *head)
{
    ListNode *p = head->next;
    while (p)
    {
        ListNode *low = p, *fast = p->next;
        while (fast)
        {
            if (low->no == fast->no)
            {
                ListNode *q = fast->next;
                low->next = q;
                fast = q;
            }
            else
            {
                fast = fast->next;
            }
        }
        p = p->next;
    }
}

int len(ListNode *head)
{
    int i = 0;
    ListNode *p = head->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

void show(ListNode *head)
{
    ListNode *p = head->next;
    while (p)
    {
        cout << p->no << " " << p->name << " " << p->price << endl;
        p = p->next;
    }
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode("0", "0", "0");
    ListNode *cur = head;
    for (int i = 0; i < n; i++)
    {
        string no, name, price;
        cin >> no >> name >> price;
        ListNode *p = new ListNode(no, name, price);
        cur->next = p;
        cur = p;
    }
    deleteEqual(head);
    cout << len(head) << endl;
    show(head);
    return 0;
}