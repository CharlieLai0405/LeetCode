#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool check(char left, char right)
    {
        bool res = false;
        if (left == '(' && right == ')')
            res = true;
        else if (left == '[' && right == ']')
            res = true;
        else if (left == '{' && right == '}')
            res = true;

        return res;
    }

    bool isValid(string s)
    {
        vector<char> store;
        for (int i = 0; i < s.size(); i++)
        {
            if (store.empty())
                store.push_back(s[i]);
            else
            {
                char temp = store[store.size() - 1];
                if (!check(temp, s[i])) // true [] {} ()
                {
                    store.push_back(s[i]);
                }
                else
                {
                    store.pop_back();
                }
            }
        }
        if (store.empty())
            return true;
        else
            return false;
    }
};