#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int position = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
            {
                return position;
            }
            if (nums[i] == target)
                return i;
            position++;
        }
        return position;
    }
};