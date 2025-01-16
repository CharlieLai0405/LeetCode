#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        bool check = true;

        for (int i = 0; i < haystack.size(); i++) 
        {
            if (haystack[i] == needle[0]) 
            {
                check = true;
                for (int j = i, x = 0; x < needle.size(); j++, x++) 
                {
                    if (haystack[j] != needle[x]) 
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                    return i;
            }
        }

        return ans;
    }
};
