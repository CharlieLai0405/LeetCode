class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int max = LLONG_MIN;
        for (int i = 0; i < sorted.size() / 2; i++)
        {
            int temp = sorted[i] + sorted[sorted.size() - 1 - i];
            if (temp > max)
                max = temp;
        }
        return max;
    }
};