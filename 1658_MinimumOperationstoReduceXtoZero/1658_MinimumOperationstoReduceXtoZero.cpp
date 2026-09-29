#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ans = 0;
        while (x > 0)
        {
            cout << nums[left] << " " << nums[right] << " " << ans << endl;
            if (nums[left] >= nums[right])
            {
                if (nums[left] <= x)
                {
                    x -= nums[left];
                    ans++;
                    cout << nums[left] << " " << ans << endl;
                    left++;
                }
                else if (nums[right] <= x)
                {
                    x -= nums[right];
                    ans++;
                    cout << nums[right] << " " << ans << endl;
                    right--;
                }
                else
                    return -1;
            }
            else if (nums[left] <= nums[right])
            {
                if (nums[right] <= x)
                {
                    x -= nums[right];
                    ans++;
                    cout << nums[right] << " " << ans << endl;
                    right--;
                }
                else if (nums[left] <= x)
                {
                    x -= nums[left];
                    ans++;
                    cout << nums[left] << " " << ans << endl;
                    left++;
                }
                else
                    return -1;
            }
            else
                return -1;
        }
        if (x == 0)
            return ans;
        else
            return -1;
    }
};

// 轉換想法 -> 找總和等於 total - x 的最長 subarray

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
            total += nums[i];
        int res = total - x;
        if (res < 0)
            return -1;
        if (res == 0)
            return nums.size();

        int max = -1;
        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            temp += nums[right];
            while (temp > res)
            {
                temp -= nums[left];
                left++;
            }
            int len = right - left + 1;
            if (len > max && temp == res)
                max = len;
        }
        if (max == -1)
            return -1;
        return nums.size() - max;
    }
};