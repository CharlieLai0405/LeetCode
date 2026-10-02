#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int ans = 0;
        vector<int> count(2, 0);
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            int num = s[right] - '0';
            count[num]++;
            while (count[0] > k && count[1] > k && right > left)
            {
                int num_l = s[left] - '0';
                count[num_l]--;
                left++;
            }
            ans = ans + (right - left + 1);
        }
        return ans;
    }
};