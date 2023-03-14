#include <iostream>
using namespace std;
#define maxsize 100
struct Queue
{
    int *base;
    int front;
    int rear;
    int tag;
};

void init(Queue &q)
{
    q.base = new int[maxsize];
    q.front = q.rear = q.tag = 0;
}

int enQueue(Queue &q, int val)
{
    if (q.front == q.rear && q.tag == 1)
    {
        return -1;
    }
    else
    {
        q.base[q.rear] = val;
        q.rear = (q.rear + 1) % maxsize;
        if (q.tag == 0)
            q.tag = 1;
    }
    return 0;
}

int dlQueue(Queue &q)
{
    if (q.front == q.rear && q.tag == 0)
    {
        return -1;
    }
    else
    {
        int val = q.base[q.front];
        q.front = (q.front + 1) % maxsize;
        if (q.tag == 1)
            q.tag = 0;
        return val;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Queue q;
        init(q);
        int val;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            enQueue(q, val);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << dlQueue(q) << " ";
        }
        cout << dlQueue(q) << endl;
    }
    return 0;
}