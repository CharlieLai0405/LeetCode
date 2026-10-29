#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size();
        int left = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};