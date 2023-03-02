#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    while (cin >> n )
    {
    	if(n==0)
			break; 
        stack<int> s;
        int num[n + 1];
        for (int i = 0; i < n - 1; i++)
            cin >> num[i];
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] == -1)
            {
                if (s.empty())
                    cout << "POP ERROR" << endl;
                else
                {
                    cout << s.top() << endl;
                    s.pop();
                }
            }
            else
            {
                s.push(num[i]);
            }
        }
    }
    return 0;
}
