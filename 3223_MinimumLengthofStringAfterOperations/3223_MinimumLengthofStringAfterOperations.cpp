#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        map<char, int> count;

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        for (map<char, int>::iterator it = count.begin(); it != count.end();
            it++) {
            cout << it->first << " " << it->second << endl;
        }

        for (map<char, int>::iterator it = count.begin(); it != count.end();
            it++) {
            while (it->second >= 3) {
                it->second = it->second - 2;
            }
        }

        for (map<char, int>::iterator it = count.begin(); it != count.end();
            it++) {
            ans = ans + it->second;
        }

        return ans;
    }
};
