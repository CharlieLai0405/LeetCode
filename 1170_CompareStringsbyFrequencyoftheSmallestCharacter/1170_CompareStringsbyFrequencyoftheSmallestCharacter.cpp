#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int lexicographically(const string &s)
    {
        if (s.empty())
            return 0;

        char temp = s[0];
        int count = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] < temp)
            {
                temp = s[i];
                count = 1;
            }
            else if (s[i] == temp)
            {
                count++;
            }
        }
        return count;
    };

    vector<int> numSmallerByFrequency(vector<string> &queries,
                                      vector<string> &words)
    {
        vector<int> ans;
        vector<int> count_words;
        for (int i = 0; i < words.size(); i++)
            count_words.push_back(lexicographically(words[i]));
        sort(count_words.begin(), count_words.end());

        for (int i = 0; i < queries.size(); i++)
        {
            int target = lexicographically(queries[i]);
            bool check = true;
            for (int j = 0; j < count_words.size(); j++)
            {
                if (count_words[j] > target)
                {
                    ans.push_back(count_words.size() - j);
                    check = false;
                    break;
                }
            }
            if (check)
                ans.push_back(0);
        }

        return ans;
    }
};