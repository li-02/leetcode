#include <iostream>
// https://www.programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#_24-%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9
/**
 * @brief 惯例加上虚拟头节点，对首元结点的操作就和其他节点操作一致了
 * 操作中涉及到4个节点，cur节点，要交换的两个节点，未改变部分的第一个节点
 * 假设当前节点为 cur->1->2->3
 * cur的next要指向2,2的next要指向1,1的next要指向3，所以要用两个临时节点指向1和3
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = cur->next->next->next;

            // 开始交换
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            // 一次移两位
            cur = cur->next->next;
        }
        return dummyNode->next;
    }
};