#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int ans = 0;
        int left = 0;
        long long product = 1;
        for (int right = 0; right < nums.size(); right++)
        {
            product *= (long long)nums[right];
            while (product >= k && right >= left)
            {
                product /= (long long)nums[left];
                left++;
            }
            long long temp = product;
            int temp_left = left;
            while (temp < k && right >= temp_left)
            {
                temp /= (long long)nums[temp_left];
                temp_left++;
                ans++;
            }
        }
        return ans;
    }
};