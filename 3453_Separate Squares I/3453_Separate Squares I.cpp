class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        unsigned long long total = 0;
        long double h = -1e18;
        long double l = 1e18;

        for (int i = 0; i < (int)squares.size(); i++)
        {
            unsigned long long side = (unsigned long long)squares[i][2];
            total += side * side;

            h = max((long double)squares[i][1] + (long double)squares[i][2], h);
            l = min((long double)squares[i][1], l);
        }

        long double half = (long double)total / 2.0;

        for (int x = 0; x < 80; x++)
        {
            long double mid = (h + l) / 2.0;
            long double area = 0.0;

            for (int i = 0; i < (int)squares.size(); i++)
            {
                long double y = (long double)squares[i][1];
                long double side = (long double)squares[i][2];

                long double height = 0.0;
                if (mid <= y)
                    height = 0.0;
                else if (mid >= y + side)
                    height = side;
                else
                    height = mid - y;

                area += height * side;
            }

            if (area >= half)
                h = mid;
            else
                l = mid;
        }

        return (double)h;
    }
};