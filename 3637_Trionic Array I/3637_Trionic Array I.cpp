class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        bool ans = false, con1 = true, con2 = true, con3 = true, check = true;
        int count = 1;
        if (nums[0] >= nums[1])
            return false;
        for (; count < nums.size() && con1; count++)
        {
            if (nums[count - 1] > nums[count])
                con1 = false;
            if (nums[count - 1] == nums[count])
                return false;
        }
        count--;
        for (; count < nums.size() && con2; count++)
        {
            if (nums[count - 1] < nums[count])
                con2 = false;
            if (nums[count - 1] == nums[count])
                return false;
        }
        count--;
        for (; count < nums.size() && con3; count++)
        {
            check = false;
            if (nums[count - 1] > nums[count])
                con3 = false;
            if (nums[count - 1] == nums[count])
                return false;
        }

        if (count == nums.size() && check)
            con3 = false;
        if (!con1 && !con2 && con3)
            ans = true;

        return ans;
    }
};