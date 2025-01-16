#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*vector<int> toBinary(int num) {
        vector<int> binary;
        long long unsigned limit = 1;

        for (; limit <= num; limit = limit * 2)
            ;

        if (limit > num)
            limit /= 2;

        while (limit > 1) {
            if (num >= limit) {
                num -= limit;
                binary.push_back(1);
            }
            else
                binary.push_back(0);
            limit /= 2;
        }
        binary.push_back(num);

        return binary;
    };

    int toTen(vector<int> num) {
        int count = 0;
        int limit = 1;
        for (int i = 1; i < num.size(); i++) {
            limit = limit * 2;
        }

        cout << limit << endl;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == 1) {
                count = count + limit;
            }
            limit = limit / 2;
        }

        return count;
    };

    vector<int> XOR(vector<int> nums_1, vector<int> nums_2)
    {
        vector <int> XOR;
        if (nums_1.size() < nums_2.size())
        {
            int temp = nums_2.size() - nums_1.size();
            for (int i = 0; i < temp; i++)
                nums_1.insert(nums_1.begin(), 0);
        }
        else if (nums_1.size() > nums_2.size())
        {
            int temp = nums_1.size() - nums_2.size();
            for (int i = 0; i < temp; i++)
                nums_2.insert(nums_2.begin(), 0);
        }

        for (int i = 0; i < nums_1.size() ; i++)
        {
            if (nums_1[i] != nums_2[i])
            {
                XOR.push_back(1);
            }
            else 
            {
                XOR.push_back(0);
            }
        }

        for (int i = 0; i < nums_1.size(); i++)
            cout << nums_1[i] << " ";
        cout << endl;

        for (int i = 0; i < nums_2.size(); i++)
            cout << nums_2[i] << " ";
        cout << endl;

        for (int i = 0; i < XOR.size(); i++)
            cout << XOR[i] << " ";
        cout << "--------------------" << endl;

        return XOR;
    };*/

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0)
            return ans = 0;
        else if (nums1.size() % 2 != 0 && nums2.size() % 2 == 0)  // °µnums2
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                ans = ans ^ nums2[i];
            }
        }
        else if (nums1.size() % 2 == 0 && nums2.size() % 2 != 0)  //°µnums1
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                ans = ans ^ nums1[i];
            }
        }
        else
        {
            int temp1 = 0;
            int temp2 = 0;
            for (int i = 0; i < nums2.size(); i++)
            {
                temp1 = temp1 ^ nums2[i];
            }
            for (int i = 0; i < nums1.size(); i++)
            {
                temp2 = temp2 ^ nums1[i];
            }
            ans = temp1 ^ temp2;
        }

        return ans;
    }
};
