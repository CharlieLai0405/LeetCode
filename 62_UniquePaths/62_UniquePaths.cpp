#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long ans = 1;
        int right = m - 1;
        int down = n - 1;

        int big, small;
        if (right <= down) {
            big = down;
            small = right;
        }
        else {
            big = right;
            small = down;
        }

        int total = right + down;
        int x = 0;
        for (int i = total; i != big; i--) {
            ans = ans * i;

            if (ans >= 12677700308232960000 && x != 1) {
                for (int j = 1; j <= small; j++)
                    ans = ans / j;
                x = 1;
            }
        }

        if (x != 1) {
            for (int i = 1; i <= small; i++)
                ans = ans / i;
        }

        return ans;
    }
};
