#include <iostream>
using namespace std;

int BF(string s, string sub)
{
    int l1 = s.size();
    int l2 = sub.size();
    int i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (s[i] == sub[j])
        {
            i++, j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= l2)
        return i - j + 1;
    else
        return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s[n + 1], sub[m + 1];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    for (int i = 0; i < m; i++)
    {
        getline(cin, sub[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (BF(s[i], sub[j]) != -1)
            {
                cout << "Network intrusion detected." << endl;
                return 0;
            }
        }
    }
    cout << "Nothing detected." << endl;
    return 0;
}