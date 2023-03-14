#include <iostream>
using namespace std;
#define maxsize 100
struct Queue
{
    int *base;
    int front;
    int rear;
};
int InitQueue(Queue &Q)
{
    Q.base = new int[maxsize];
    Q.front = Q.rear = 0;
    return 0;
}
int EnQueue(Queue &Q, int e)
{
    if (Q.rear == (Q.front - 1 + maxsize) % maxsize)
        return -1;
    Q.base[Q.front] = e;
    Q.front = (Q.front - 1 + maxsize) % maxsize;
    return 0;
}
int DeQueue(Queue &Q)
{
    if (Q.front == Q.rear)
        return -1;
    int e = Q.base[Q.rear];
    Q.rear = (Q.rear - 1 + maxsize) % maxsize;
    return e;
}
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        Queue Q;
        InitQueue(Q);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            EnQueue(Q, x);
        }
        for (int j = 0; j < n - 1; j++)
            cout << DeQueue(Q) << " ";
        cout << DeQueue(Q) << endl;
    }
    return 0;
}
