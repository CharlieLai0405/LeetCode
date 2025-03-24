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

        // �t������
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            diff[start] += 1;
            diff[end + 1] -= 1;
        }

        int cur = 0;
        int prev = 1;
        int count = 0;

        // �ھڦ��аO���I�Ƨǫ�] prefix sum
        for (auto& [day, delta] : diff) {
            if (cur == 0) {
                count += (day - prev); // �e�@�q���O�S�|ĳ��
            }
            cur += delta;
            prev = day;
        }

        // �̫�@�q�A�p�G�̫�@�q�O�S�|ĳ��
        if (cur == 0 && prev <= days) {
            count += (days - prev + 1);
        }

        return count;
    }
};
