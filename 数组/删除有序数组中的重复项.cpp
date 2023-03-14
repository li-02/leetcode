#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 删除有序数组中的重复项
 * 还是双指针，快指针用来遍历数组，慢指针用来表示非重复值该填入的下标
 * 第一个数肯定不重复，所以下标从1开始
 *
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 1, fast = 1;
        for (; fast < nums.size();)
        {
            if (nums[fast] == nums[fast - 1])
            {
                fast++;
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};