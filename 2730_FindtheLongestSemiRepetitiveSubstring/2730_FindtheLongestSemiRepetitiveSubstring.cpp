#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        vector<int> count;
        int prev = -1;
        int cnt = 0;
        for (char c : s)
        {
            int num = c - '0';
            if (num != prev)
            {
                prev = num;
                cnt++;
            }
            else
            { // 00 11 22 33
                cnt--;
                count.push_back(cnt);
                count.push_back(-1);
                cnt = 0;
            }
        } // 5 -1 2 -1 3 -1 6 -1 8 -1 9 -1 -1
        count.push_back(cnt);
        bool same = false;
        vector<int> FindMax;
        int ans = 0;
        int total = count[0];
        for (int i = 1; i < count.size(); i++)
        {
            if (count[i] == -1 && same)
            {
                FindMax.push_back(total);
                total = count[i];
            }
            else if (count[i] == -1 && !same)
            {
                same = true;
                total += count[i];
            }
            else
                total += count[i];
        }
        if (!same)
            ans = s.size() - 4;
        else
        {
            auto max_it = max_element(FindMax.begin(), FindMax.end());
            ans = *max_it;
        }
        return ans + 4;
    }
};

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int left = 0;
        int same = 0;
        int ans = 1;

        for (int right = 1; right < s.size(); right++)
        {
            // 發現一組相鄰相同
            if (s[right] == s[right - 1])
            {
                same++;
            }

            // 如果目前範圍裡有超過一組相鄰相同
            while (same > 1)
            {
                // 如果 left 這邊剛好是一組相鄰相同
                // 把它移出範圍後，same 就少一組
                if (s[left] == s[left + 1])
                {
                    same--;
                }

                left++;
            }

            int len = right - left + 1;
            ans = max(ans, len);
        }

        return ans;
    }
};