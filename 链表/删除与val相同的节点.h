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
        // ����һ������ͷ�ڵ㣬֮���ɾ��������һ���ˣ�����һ���ṹ��ڵ�
        LinkedNode *dummyNode = new LinkedNode(0);
        dummyNode->next = head;
        // ����һ��ָ��
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