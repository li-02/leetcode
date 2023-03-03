#include <iostream>
using namespace std;

void reverse(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(s[start], s[end]);         // 交换首尾字符
    reverse(s, start + 1, end - 1); // 递归调用
}

int main()
{
    string s;
    // getline可以接受空格,cin以空格结尾
    while (getline(cin, s))
    {
        if (s == "0")
        {
            break;
        }
        reverse(s, 0, s.length() - 1);
        cout << s << endl;
    }
    return 0;
}
