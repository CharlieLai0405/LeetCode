#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = nums.size() + 2;
        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            temp += nums[right];
            while (temp >= target)
            {
                int len = right - left + 1;
                if (len < ans)
                    ans = len;
                temp -= nums[left];
                left++;
            }
        }
        if (ans == nums.size() + 2)
            return 0;
        return ans;
    }
};

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // total - target 的最小
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return 1;
            total += nums[i];
        }
        int goal = total - target;
        if (goal < 0)
            return 0;
        else if (goal == 0)
            return nums.size();
        int ans = 0;
        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            cout << temp << " " << nums[right] << " " << nums[left] << " ";
            temp += nums[right];
            while (temp > goal)
            {
                temp -= nums[left];
                left++;
            }
            int len = right - left + 1;
            cout << len << endl;
            if (len > ans)
                ans = len;
        }
        return nums.size() - ans;
    }
};