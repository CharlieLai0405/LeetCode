#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries)
    {
        vector<bool> ans;
        vector<vector<bool>> check(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < prerequisites.size(); i++)
        {
            // cout <<prerequisites[i][0] << " " << prerequisites[i][1] << endl;
            check[prerequisites[i][0]][prerequisites[i][1]] = true;
        }

        for (int i = prerequisites.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < check[prerequisites[i][1]].size(); j++)
            {
                if (check[prerequisites[i][1]][j]) // check[[i][1]][j] = true
                {
                    check[prerequisites[i][0]][j] = true;
                }
            }
        }

        for (int i = 0; i < prerequisites.size(); i++)
        {
            for (int j = 0; j < check[prerequisites[i][1]].size(); j++)
            {
                if (check[prerequisites[i][1]][j]) // check[[i][1]][j] = true
                {
                    check[prerequisites[i][0]][j] = true;
                }
            }
        }

        for (int i = prerequisites.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < check[prerequisites[i][1]].size(); j++)
            {
                if (check[prerequisites[i][1]][j]) // check[[i][1]][j] = true
                {
                    check[prerequisites[i][0]][j] = true;
                }
            }
        }

        for (int i = 0; i < check.size(); i++)
        {
            for (int j = 0; j < check[i].size(); j++)
            {
                if (i == j)
                {
                    check[i][j] = true;
                }
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(check[queries[i][0]][queries[i][1]]);
        }

        /*for (int i = 0; i < check.size(); i++)
        {
            // cout << "check[i].size():" << check[i].size() << endl;
            for (int j = 0; j < check[i].size(); j++)
            {
                // cout << "i:" << i << " j:" << j << " "<<check[i][j] << endl;
                cout << check[i][j] << " ";
            }
            cout << endl;
        }*/

        return ans;
    }
};