#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int first = 2;
        int second = 3;
        int ans = 0;
        int run = n - 3;

        if (n == 1)
            ans = 1;
        else if (n == 2)
            ans = first;
        else if (n == 3)
            ans = second;
        else {
            while (run != 0) {

                ans = first + second;
                first = second;
                second = ans;
                run--;
            }
        }

        return ans;
    }
};