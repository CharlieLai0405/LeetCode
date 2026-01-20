class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }

        int hi = min(m, n);
        int lo = 0;

        while (lo < hi)
        {
            int mid = (hi + lo + 1) / 2;
            bool check = false;
            int sum = 0;
            int len = mid;
            for (int i = 0; i + len <= m; i++)
            {
                for (int j = 0; j + len <= n; j++)
                {
                    sum = prefix[i + len][j + len] - prefix[i + len][j] - prefix[i][j + len] + prefix[i][j];
                    if (sum <= threshold)
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                    break;
            }

            if (check)
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};