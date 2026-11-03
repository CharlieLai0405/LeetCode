#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
        {
            int left = 0;
            int right = potions.size();
            int first = potions.size();
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                unsigned long long temp = (unsigned long long)spells[i] * (unsigned long long)potions[mid];
                if (temp >= success)
                {
                    first = mid;
                    right = mid;
                }
                else
                    left = mid + 1;
            }
            ans.push_back(potions.size() - first);
        }
        return ans;
    }
};