#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        for (int i = 0; i < strs.size(); i++)
        {
            int count = 0;
            vector<string> temp;
            for (int j = 0; j < strs.size(); j++)
            {
                string temp_stringI = strs[i];
                for (int z = 0; z < strs[j].size(); z++)
                {
                    if (strs[i].size() != strs[j].size())
                        break;
                    else 
                    {
                        
                        for (int x = 0; x < strs[i].size(); x++)
                        {
                            if (temp_stringI[x] == strs[j][z])
                            {
                                temp_stringI.erase(temp_stringI.begin() + x);
                            }
                            else
                                break;
                        }
                    }
                }
                if (temp_stringI.size() == 0)
                {
                    temp.push_back(strs[i]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
