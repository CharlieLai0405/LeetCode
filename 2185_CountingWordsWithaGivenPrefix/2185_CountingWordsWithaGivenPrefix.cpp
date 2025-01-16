#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            bool check = true;
            if (words[i][0] == pref[0] && words[i].size() >= pref.size())
            {
                for (int j = 0; j < pref.size(); j++)
                {
                    if (words[i][j] != pref[j])
                        check = false;
                }
                if (check)
                    ans++;
            }
        }
        return ans;
    }
};