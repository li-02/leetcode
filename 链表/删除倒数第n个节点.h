#include <iostream>
#include <cstdio>
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/submissions/
/**
 * @brief 要一趟删除倒数第n个，可以使用双指针，令双指针距离为n，当快指针指向末尾NULL时，慢指针就指向了要删除的节点
 * 为了方便删除，可以先让快指针多走一步，慢指针最后会指向要删除节点的前一个节点，删除方便
 *
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        while (n-- && fast != NULL)
        {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyNode->next;
    }
};