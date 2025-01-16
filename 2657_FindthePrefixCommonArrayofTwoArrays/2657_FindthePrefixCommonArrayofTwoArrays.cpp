#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;

        for (int i = 0; i < A.size(); i++)
        {
            int count = 0;
            for (int j = 0; j <= i; j++)
            {
                vector<int>::iterator it = find(B.begin(), B.end(), A[j]);
                int temp = distance(B.begin(), it);
                if (temp <=i)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }

        return ans;
    }
};
