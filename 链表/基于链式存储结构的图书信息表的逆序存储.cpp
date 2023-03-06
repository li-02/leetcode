#include <iostream>
using namespace std;

struct ListNode
{
    string no;
    string name;
    string price;
    ListNode *next;
    ListNode(string no, string name, string price) : no(no), name(name), price(price), next(nullptr) {}
};

void show(ListNode *l)
{
    ListNode *p = l->next;
    while (p)
    {
        cout << p->no << " " << p->name << " " << p->price << endl;
        p = p->next;
    }
}

/**
 * @brief 主要复习头插法创建链表
 *
 * @return int
 */
int main()
{
    int n;
    cin >> n;
    string no, name, price;
    ListNode *head = new ListNode("0", "0", "0");
    ListNode *cur = head;
    for (int i = 0; i < n; i++)
    {
        cin >> no >> name >> price;
        ListNode *p = new ListNode(no, name, price);
        p->next = cur->next;
        cur->next = p;
    }
    show(head);
    return 0;
}