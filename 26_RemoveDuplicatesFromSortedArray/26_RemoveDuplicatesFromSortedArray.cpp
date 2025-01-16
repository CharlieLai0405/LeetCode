#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int last = -1000;

        for (int i = 0; i < nums.size(); i++) {
            if (last != nums[i]) {
                last = nums[i];
                ans++;
            }
            else {
                nums.erase(nums.begin() + ans);
                i--;
            }
        }

        return ans;
    }
};