#include <iostream>
using namespace std;

bool binarySearch(int a[], int left, int right, int target)
{
    if (left == right)
    {
        if (a[left] == target)
            return true;
        else
            return false;
    }
    else
    {
        int mid = left + (right - left) / 2;
        if (a[mid] < target)
            return binarySearch(a, mid + 1, right, target);
        else if (a[mid] > target)
            return binarySearch(a, left, mid - 1, target);
        else
            return true;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        // 动态内存
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int t;
        cin >> t;
        if (binarySearch(a, 0, n, t))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
        delete[] a;
    }
    return 0;
}