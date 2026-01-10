class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        long long sum = 0;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int best = 0;

        for (int i = 0; i < s1.size(); i++)
            sum += int(s1[i]);

        for (int i = 0; i < s2.size(); i++)
            sum += int(s2[i]);

        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + int(s1[i - 1]);
                    if (dp[i][j] > best)
                        best = dp[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return sum - (best * 2);
    }
};