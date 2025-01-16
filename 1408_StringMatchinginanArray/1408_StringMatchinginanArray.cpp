#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j)
                {
                    for (int loc = 0; loc < words[j].size(); loc++)
                    {
                        if (temp[0] == words[j][loc])
                        {
                            bool push = true;
                            for (int check = 0; check < temp.size(); check++)
                            {
                                if (temp[check] != words[j][loc + check])
                                {
                                    push = false;
                                    break;
                                }
                            }
                            if (push)
                            {
                                bool puch_check = true;
                                for (int ans_check = 0; ans_check < ans.size(); ans_check++)
                                {
                                    if (ans[ans_check] == temp)
                                        puch_check = false;
                                }
                                if (puch_check)
                                    ans.push_back(temp);
                            }
                        }
                    }
                }
            }

        }

        return ans;
    }
};
