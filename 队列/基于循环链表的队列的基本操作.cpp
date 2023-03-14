#include <iostream>
#include <stdlib.h>
using namespace std;
struct Queue
{
    int data;
    Queue *next;
    Queue(int data) : data(data), next(nullptr) {}
};
void InitQueue(Queue *&Q)
{
    Q = new Queue(0);
    Q->next = Q;
}
/**
 * @brief 这里的指针,指向队尾了
 *
 * @param Q
 * @param e
 */
void Push(Queue *&Q, int e)
{
    Queue *p = new Queue(e);
    p->next = Q->next;
    Q->next = p;
    Q = p;
}
void Pop(Queue *&Q)
{
    Queue *q = Q->next->next;
    cout << q->data << " ";
    Q->next->next = q->next;
    if (q == Q)
        Q = Q->next;
    delete q;
}
int IsEmpty(Queue *Q)
{
    return Q->next == Q ? 1 : 0;
}
int main()
{
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        Queue *Q;
        InitQueue(Q);
        while (n--)
        {
            int e;
            cin >> e;
            Push(Q, e);
        }
        while (m--)
            Pop(Q);
        if (IsEmpty(Q))
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}
