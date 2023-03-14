#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 使用双指针
 * 慢指针用来表示该填入的数的下标，快指针用来遍历数组
 *
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int low, fast;
        low = fast = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[low++] = nums[fast];
            }
        }
        return low;
    }
};