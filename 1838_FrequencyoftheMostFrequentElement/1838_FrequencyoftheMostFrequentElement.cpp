#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return nums.size();
        sort(nums.begin(), nums.end());
        vector<int> sub(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++)
            sub[i] = sub[i - 1] + (nums[i] - nums[i - 1]);
        int ans = 0;
        int left = 0;
        long long total = 0;
        int count = 0;
        for (int right = 1; right < sub.size(); right++)
        {
            count++;
            total += (long long)(sub[right] - sub[right - 1]) * count;
            while (total > k)
            {
                total -= sub[right] - sub[left];
                left++;
                count--;
            }
            if (count > ans)
                ans = count;
        }
        return ans + 1;
    }
};

// Time Exceeded
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return nums.size();
        sort(nums.begin(), nums.end());
        vector<int> sub;
        for (int i = 1; i < nums.size(); i++)
            sub.push_back(nums[i] - nums[i - 1]);
        int ans = 0;
        int left = 0;
        long long total = 0;
        int count = 0;
        for (int right = 0; right < sub.size(); right++)
        {
            count++;
            total += sub[right] * count;
            while (total > k)
            {
                for (int j = left; j <= right; j++)
                    total -= sub[j];
                left++;
                count--;
            }
            if (count > ans)
                ans = count;
        }
        return ans + 1;
    }
};

// WRONG

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        auto it_max = max_element(nums.begin(), nums.end());
        vector<int> array(*it_max + k + 5, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            array[nums[i]]++;
            array[nums[i] + k + 1]--;
        }
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < array.size(); i++)
        {
            temp += array[i];
            if (temp > ans)
                ans = temp;
        }
        return ans;
    }
};