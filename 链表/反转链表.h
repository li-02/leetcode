#include <iostream>
/**
 * @brief 利用双指针，pre记录前半部分已经逆转的节点，cur记录还未逆转的第一个节点
 *        每次逆转前，要记住下一个节点tmp
 */
class Solution
{
    // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};