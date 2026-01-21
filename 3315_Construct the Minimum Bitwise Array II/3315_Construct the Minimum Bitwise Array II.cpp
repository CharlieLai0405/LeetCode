// nums [010,011,101,111]
// ans [-1,001,100,011]

// nums[01011,01101,011111]
// ans [01001,01100,011110]
//     [01010,01101,011111]
class Solution
{
public:
    vector<int> Bit(int num)
    {
        int temp = 1;
        vector<int> bit;
        while (temp <= num)
        {
            temp *= 2;
        }
        temp /= 2;
        while (temp > 0)
        {
            if (temp <= num)
            {
                num -= temp;
                bit.push_back(1);
            }
            else
            {
                bit.push_back(0);
            }
            temp /= 2;
        }
        return bit;
    };

    int Ten(vector<int> bit)
    {
        int number = 0;
        int temp = 1;
        for (int i = bit.size() - 1; i >= 0; i--)
        {
            if (bit[i] == 1)
                number += temp;
            temp *= 2;
        }
        return number;
    };

    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 2)
                ans[i] = -1;
            else
            {
                vector<int> num_bit = Bit(nums[i]);
                for (int j = num_bit.size() - 1; j > 0; j--)
                {
                    if (num_bit[j - 1] == 0)
                    {
                        num_bit[j] = 0;
                        break;
                    }
                    else if (j == 1 & num_bit[j - 1] == 1)
                    {
                        num_bit[j - 1] = 0;
                        break;
                    }
                }
                ans[i] = Ten(num_bit);
            }
        }
        return ans;
    }
};