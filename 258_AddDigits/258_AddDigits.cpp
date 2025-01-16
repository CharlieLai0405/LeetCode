#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ans = 0;

        while (num >= 10) {
            vector<int> digit;
            int temp = num;
            while (temp >= 10) {
                int dig = temp % 10;
                digit.push_back(dig);
                temp = temp / 10;
            }
            digit.push_back(temp);
            for (int i = 0; i < digit.size(); i++)
                ans = ans + digit[i];

            if (ans < 10)
                return ans;
            num = ans;
            ans = 0;
        }

        return num;
    }
};
