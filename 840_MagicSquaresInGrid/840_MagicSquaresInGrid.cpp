<<<<<<< HEAD
class Solution
{
public:
    bool isMagic3x3(vector<vector<int>> &grid, int r, int c)
    {
        // 中心必為 5
        if (grid[r + 1][c + 1] != 5)
            return false;

        // 檢查 1~9 且 distinct
        bool seen[10];
        for (int i = 0; i < 10; i++)
            seen[i] = false;

        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                int x = grid[i][j];
                if (x < 1 || x > 9)
                    return false;
                if (seen[x])
                    return false;
                seen[x] = true;
            }
        }

        int s = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // rows
        if (grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] != s)
            return false;
        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != s)
            return false;

        // cols
        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != s)
            return false;
        if (grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] != s)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != s)
            return false;

        // diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != s)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != s)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int R = (int)grid.size();
        int C = (int)grid[0].size();
        if (R < 3 || C < 3)
            return 0;

        int ans = 0;
        for (int r = 0; r <= R - 3; r++)
        {
            for (int c = 0; c <= C - 3; c++)
            {
                if (isMagic3x3(grid, r, c))
                    ans++;
            }
        }
        return ans;
    }
};
=======
class Solution
{
public:
    bool isMagic3x3(vector<vector<int>> &grid, int r, int c)
    {
        // 中心必為 5
        if (grid[r + 1][c + 1] != 5)
            return false;

        // 檢查 1~9 且 distinct
        bool seen[10];
        for (int i = 0; i < 10; i++)
            seen[i] = false;

        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                int x = grid[i][j];
                if (x < 1 || x > 9)
                    return false;
                if (seen[x])
                    return false;
                seen[x] = true;
            }
        }

        int s = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // rows
        if (grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] != s)
            return false;
        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != s)
            return false;

        // cols
        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != s)
            return false;
        if (grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] != s)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != s)
            return false;

        // diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != s)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != s)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int R = (int)grid.size();
        int C = (int)grid[0].size();
        if (R < 3 || C < 3)
            return 0;

        int ans = 0;
        for (int r = 0; r <= R - 3; r++)
        {
            for (int c = 0; c <= C - 3; c++)
            {
                if (isMagic3x3(grid, r, c))
                    ans++;
            }
        }
        return ans;
    }
};
>>>>>>> b7d56f8e7d7e223faa8a4bbd7083b49d97579ed1
