#include <iostream>
#include <vector>
#include < algorithm >

using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> store;

        for (int i = 0; i < nums.size(); i++)
        {
            if (find(store.begin(), store.end(), nums[i]) == store.end())  // not in vector
            {
                store.push_back(nums[i]);
            }
            else //in vector
            {
                if (nums.size() < 3)
                    nums.clear();
                else
                    nums.erase(nums.begin(), nums.begin() + 3);
                i = 0;
                ans++;
                store.clear();
                store.push_back(nums[i]);
            }
        }
        return ans;
    }
};