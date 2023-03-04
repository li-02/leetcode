#include <iostream>
using namespace std;

/**
 * @brief 如果写成 string c的话,c初始化为空,长度为0,在循环中下标越界
 * 所以要初始化一个空格组成的字符串
 *
 * @return int
 */
int main()
{
    int pos;
    while (cin >> pos)
    {
        if (pos == 0)
            return 0;
        string a, b;
        cin >> a;
        cin >> b;
        string c(a.size() + b.size(), ' ');
        for (int i = 0; i < pos - 1; i++)
        {
            c[i] = a[i];
        }
        for (int i = pos - 1, j = 0; j < b.size(); i++, j++)
        {
            c[i] = b[j];
        }
        for (int i = pos - 1 + b.size(), j = pos - 1; j < a.size(); j++, i++)
        {
            c[i] = a[j];
        }
        cout << c << endl;
    }
    return 0;
}