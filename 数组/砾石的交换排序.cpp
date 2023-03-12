#include <iostream>
using namespace std;

template <class T>
void exchange(T &a, T &b)
{
    T t;
    t = b;
    b = a;
    a = t;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        char ch[100];
        for (int i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        // i前面的全是红色，k后面的都是蓝色
        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (ch[j] == 'W')
                j++;
            else if (ch[j] == 'R')
            {
                exchange(ch[j], ch[i]);
                i++;
                j++;
            }
            else
            {
                exchange(ch[j], ch[k]);
                k--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ch[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}
// r w b
// i 2 j 3 k 2