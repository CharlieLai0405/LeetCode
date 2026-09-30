#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        vector<int> check(1000005, 0);
        int ans = nums.size() + 2;
        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (check[nums[right]] == 0)
                temp += nums[right];
            check[nums[right]]++;
            while (temp >= k)
            {
                int len = right - left + 1;
                if (len < ans)
                    ans = len;
                check[nums[left]]--;
                if (check[nums[left]] == 0)
                    temp -= nums[left];
                left++;
            }
        }
        if (ans == nums.size() + 2)
            return -1;
        return ans;
    }
};