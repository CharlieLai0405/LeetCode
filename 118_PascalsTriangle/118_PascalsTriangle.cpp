#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> insert;

            if (i != 0)
            {
                insert.push_back(1);
                for (int j = 1; j <ans[i-1].size() ; j++) {
                        int temp = 0;                        
                        temp = ans[i - 1][j - 1] + ans[i - 1][j];                        
                        insert.push_back(temp);                   
                }
            }

            insert.push_back(1);
            ans.push_back(insert);
        }
        return ans;
    }
};