#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/// Time Limit Exceeded
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int ans = 0;
        vector<int> array(100000 + k + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                array[nums[i] + j]++;
                if ((nums[i] - j) >= 0)
                    array[nums[i] - j]++;
            }
            array[nums[i]]++;
        }

        auto max_it = max_element(array.begin(), array.end());
        ans = *max_it;

        return ans;
    }
};

// solution 差分陣列

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int ans = 0;
        vector<int> array(100000 + k + 5, 0);
        int right = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            left = nums[i] - k;
            right = nums[i] + k;
            if (left < 0)
                left = 0;
            array[left]++;
            array[right + 1]--;
        }

        int cur = 0;
        for (int i = 0; i < array.size(); i++)
        {
            cur += array[i];
            if (cur > ans)
                ans = cur;
        }

        return ans;
    }
};