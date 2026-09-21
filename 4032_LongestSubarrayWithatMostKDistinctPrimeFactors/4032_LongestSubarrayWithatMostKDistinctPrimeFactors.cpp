#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> GetPrime(int num)
    {
        vector<int> count;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                count.push_back(i);
                while (num % i == 0)
                    num /= i;
            }
        }
        if (num > 1)
            count.push_back(num);

        return count;
    };

    int longestSubarray(vector<int> &nums, int k)
    {
        int ans = 0;
        int left = 0;
        int dis = 0;
        map<int, int> count;
        for (int right = 0; right < nums.size(); right++)
        {
            vector<int> temp = GetPrime(nums[right]);
            for (int j = 0; j < temp.size(); j++)
            {
                if (count[temp[j]] == 0)
                    dis++;
                count[temp[j]]++;
            }
            while (dis > k)
            {
                vector<int> leftPrime = GetPrime(nums[left]);
                for (int a = 0; a < leftPrime.size(); a++)
                {
                    count[leftPrime[a]]--;
                    if (count[leftPrime[a]] == 0)
                        dis--;
                }
                left++;
            }
            int len = right - left + 1;
            if (len > ans)
                ans = len;
        }
        return ans;
    }
};