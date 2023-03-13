#include <iostream>
using namespace std;
#define MAXSIZE 10000

typedef struct
{
    int top[2], bot[2];
    int *V;
    int m;
} DStack;

int InitDStack(DStack &S, int m)
{
    S.V = new int[m];
    S.bot[0] = S.top[0] = -1;
    S.bot[1] = S.top[1] = m;
    return 1;
}

int IsEmpty(DStack S, int i)
{
    if (S.top[i] == S.bot[i])
        return 0;
    else
        return 1;
}

int IsFull(DStack S)
{
    if (S.top[0] + 1 == S.top[1])
        return 1;
    else
        return 0;
}

int DPush(DStack &S, int i, int x)
{
    if (S.top[1] - S.top[0] == 1)
        return 0;
    if (i == 0)
    {
        S.top[0]++;
        S.V[S.top[0]] = x;
    }
    else
    {
        S.top[1]--;
        S.V[S.top[1]] = x;
    }
    return 1;
}

int DPop(DStack &S, int i, int &x)
{
    if (S.top[i] == S.bot[i])
    {
        return 0;
    }

    if (i == 0)
    {
        x = S.V[S.top[0]];
        S.top[0]--;
    }
    else if (i == 1)
    {
        x = S.V[S.top[1]];
        S.top[1]++;
    }
    return 1;
}

int main()
{
    DStack S;

    int m;
    int a, b, c, d;
    int e;
    int i;
    while (1)
    {
        cin >> m;
        if (m == 0)
            break;
        InitDStack(S, m);
        cin >> a >> b >> c >> d;
        for (i = 0; i < a; i++)
        {
            cin >> e;
            DPush(S, 0, e);
        }

        for (i = 0; i < b; i++)
        {
            cin >> e;
            DPush(S, 1, e);
        }
        cout << IsFull(S) << endl;

        for (i = 0; i < c; i++)
        {
            DPop(S, 0, e);
            cout << e << " ";
        }
        cout << IsEmpty(S, 0) << endl;

        for (i = 0; i < d; i++)
        {
            DPop(S, 1, e);
            cout << e << " ";
        }
        cout << IsEmpty(S, 1) << endl;
    }
    return 0;
}