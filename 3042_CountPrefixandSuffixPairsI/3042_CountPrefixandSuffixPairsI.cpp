#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        bool push = true;

        for (int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            temp.re
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j)
                {
                    for (int loc = 0; loc < words[j].size(); loc++)
                    {
                        if (temp[0] == words[j][loc])
                        {
                            
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
                                ans++;
                            }
                        }
                    }
                }
            }

        }

        return ans;
    }
};
