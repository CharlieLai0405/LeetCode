#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        bool ans = false;
        vector<int> store;

        store.push_back(0);
        for (int i = 0; i < derived.size(); i++)
        {
            //cout << "derived[i]:" << derived[i] << " " << derived.size() << " " << i << endl;
            if (derived[i] == 0)
            {
                store.push_back(store[i]);
            }
            else if (derived[i] == 1)
            {
                store.push_back((store[i] + 1) % 2);
            }

            // cout << store[] << " " << store[] << endl;
            if (i == derived.size() - 1)
            {
                cout << store[0] << " " << store[derived.size() - 1] << endl;
                int temp = store[0] ^ store[derived.size() - 1];
                cout << temp << endl;
                if (temp == derived[i])
                {
                    ans = true;
                }
                else
                {
                    return ans = false;
                }
            }
            else // i<derived.size()-1
            {
                cout << store[i] << " " << store[i + 1] << endl;
                int temp = store[i] ^ store[i + 1];
                cout << temp << endl;
                if (temp == derived[i])
                {
                    ans = true;
                }
                else
                {
                    return ans = false;
                }
            }
        }

        return ans;
    }
};
