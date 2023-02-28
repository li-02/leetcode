#include "MyLinkedList.h"

class Solution
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    LinkedNode *removeElements(LinkedNode *head, int val)
    {
        // 定义一个虚拟头节点，之后的删除操作就一致了，这是一个结构体节点
        LinkedNode *dummyNode = new LinkedNode(0);
        dummyNode->next = head;
        // 这是一个指针
        LinkedNode *cur = dummyNode;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                LinkedNode *t = cur->next;
                cur->next = t->next;
                delete t;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};