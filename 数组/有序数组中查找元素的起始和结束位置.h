#include <vector>
class Solution
{
private:
    int getRight(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] <= target)
            {
                left = mid + 1;
                rightBorder = left;
            }
            else
            {
                right = mid - 1;
            }
        }
        return rightBorder;
    }
    int getLeft(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] >= target)
            {
                right = mid - 1;
                leftBorder = right;
            }
            else
            {
                left = mid + 1;
            }
        }
        return leftBorder;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int rightB = getRight(nums, target);
        int leftB = getLeft(nums, target);
        vector<int> a = {-1, -1};
        vector<int> b = {leftB + 1, rightB - 1};
        if (rightB == -2 || leftB == -2)
            return a;
        if (rightB - leftB > 1)
            return b;
        return a;
    }
};
