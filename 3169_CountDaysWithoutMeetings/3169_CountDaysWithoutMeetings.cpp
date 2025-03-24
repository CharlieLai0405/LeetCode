#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> diff;

        // 差分紀錄
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            diff[start] += 1;
            diff[end + 1] -= 1;
        }

        int cur = 0;
        int prev = 1;
        int count = 0;

        // 根據有標記的點排序後跑 prefix sum
        for (auto& [day, delta] : diff) {
            if (cur == 0) {
                count += (day - prev); // 前一段都是沒會議的
            }
            cur += delta;
            prev = day;
        }

        // 最後一段，如果最後一段是沒會議的
        if (cur == 0 && prev <= days) {
            count += (days - prev + 1);
        }

        return count;
    }
};
