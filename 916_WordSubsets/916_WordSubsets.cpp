#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    struct word {
        char ch;
        int count;
    };
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<vector<word>> store_2;

        for (int i = 0; i < words2.size(); i++) {
            vector<word> temp;
            for (int j = 0; j < words2[i].size(); j++) {
                if ()
            }
            store_2.push_back(temp);
        }

        map<char, int> compare = store_2[0];

        for (int i = 1; i < store_2.size(); i++)
        {
            for (map<char, int>::iterator j = store_2[i].begin(); j != store_2[i].end(); j++)
            {
                char ch = j.
                if ())
                {
                    if (compare[store_2[i][j]] > store_2[i][j])
                    {
                        compare[store_2[i][j]] = store_2[i][j];
                    }
                }
                else {
                    compare[store_2[i][j]] = store_2[i][j];
                }
            }
        }

        bool check = true;
        vector<map<char, int>> store_1;
        for (int i = 0; i < words1.size(); i++) {
            map<char, int> temp;
            for (int j = 0; j < words1[i].size(); j++) {
                temp[words1[i][j]]++;
            }
            store_1.push_back(temp);
        }

        vector<map<char, int>> temp_count = store_2;

        for (int)

            return ans;
    }
};