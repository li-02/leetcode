#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 移动所有的0到数组末尾，其余元素保持相对位置
 * 还是双指针，先将所有不是0的元素前移，后面的所有元素赋值为0即可
 * fast用来遍历数组，slow表示要填入的位置
 */
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow, fast;
        slow = fast = 0;
        for (; fast < nums.size();)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
            else
            {
                fast++;
            }
        }
        for (int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};