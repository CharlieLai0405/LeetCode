#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool test = false;
        if (s.size() == 0)
            return count;
        for (int i = s.size() - 1; i != 0; i--)
        {
            if (s[i] == ' ')
                s.erase(i);
            else
                break;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count = 0;
                test = true;
            }
            count++;
        }
        if (test)
            count--;

        return count;
    }
};