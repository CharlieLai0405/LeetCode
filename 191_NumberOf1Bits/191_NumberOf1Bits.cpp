#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int binary = 1;
        int ans = 0;

        while (n >= binary)
            binary = binary * 2;
        
        while (n != 0)
        {
            if (n >= binary)
            {
                n -= binary;
                ans++;
            }
            binary /= 2;
        }

        return ans;
    }
};
