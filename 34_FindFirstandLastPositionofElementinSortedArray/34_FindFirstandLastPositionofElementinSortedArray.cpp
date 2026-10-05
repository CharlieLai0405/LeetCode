#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int find(vector<int> &nums, int target, bool findleft)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                ans = mid;
                if (findleft)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return ans;
    };
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        ans[0] = find(nums, target, true);
        ans[1] = find(nums, target, false);
        return ans;
    }
};