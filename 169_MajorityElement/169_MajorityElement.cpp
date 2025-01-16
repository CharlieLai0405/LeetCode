#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:
    struct number {
        int number = 0;
        int count = 0;
    };

    int majorityElement(vector<int>& nums) {
        vector<number> check;
        bool run = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < check.size(); j++) {
                if (check[j].number == nums[i]) {
                    check[j].count++;
                    run = false;
                }
            }
            if (run) {
                number temp;
                temp.count = 0;
                temp.number = nums[i];
                check.push_back(temp);
            }
            run = true;
        }

        int ans = -1;
        int answer = 0;
        for (int i = 0; i < check.size(); i++) {
            if (ans < check[i].count) {
                ans = check[i].count;
                answer = check[i].number;
            }
        }

        return answer;
    }
};