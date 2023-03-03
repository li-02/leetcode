#include <iostream>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "0")
            return 0;
        int arr[36] = {0};
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                arr[int(str[i]) - 48]++;
            }
            else
            {
                arr[int(str[i]) - 65 + 10]++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 0)
                continue;
            cout << char(i + 48) << ":" << arr[i] << endl;
        }
        for (int i = 10; i < 36; i++)
        {
            if (arr[i] == 0)
                continue;
            cout << char(i + 65 - 10) << ":" << arr[i] << endl;
        }
    }
}