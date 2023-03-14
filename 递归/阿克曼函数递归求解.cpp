#include <iostream>
using namespace std;

int Ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (m > 0 && n == 0)
        return Ackermann(m - 1, 1);
    if (m > 0 && n > 0)
        return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (!m && !n)
            break;
        cout << Ackermann(m, n) << endl;
    }
    return 0;
}