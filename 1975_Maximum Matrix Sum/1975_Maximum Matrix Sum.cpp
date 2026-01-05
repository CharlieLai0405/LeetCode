class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int neg = 0;
        long long min = LLONG_MAX;
        long long sum = 0;
        bool isZero = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] == 0)
                    isZero = true;
                else if (matrix[i][j] < 0)
                    neg++;

                if (min >= abs(matrix[i][j]))
                    min = abs(matrix[i][j]);
            }
        }

        cout << min;
        if (neg % 2 != 0 && !isZero)
            sum = sum - min - min;

        return sum;
    }
};