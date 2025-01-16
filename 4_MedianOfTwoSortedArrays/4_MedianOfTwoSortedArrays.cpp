#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float ans = 0;
        int j = 0;
        for (int i = 0; i < nums2.size();) {
            if (j >= nums1.size()) {
                for (; i < nums2.size(); i++)
                    nums1.push_back(nums2[i]);
                break;
            }

            if (nums2[i] <= nums1[j]) {
                nums1.insert(nums1.begin() + j, nums2[i]);
                i++;
            }
            else
                j++;
        }

        /*for (int i = 0; i < nums1.size(); i++)
            cout << nums1[i] << " " << endl;*/

        int temp = nums1.size() % 2;
        int position = nums1.size() / 2;
        if (temp == 0) { // °¸¼Æ
            int t = nums1[position] + nums1[position - 1];
            ans = t / 2;
            if (t % 2 != 0)
                ans += 0.5;
        }
        else    // ©_¼Æ
            ans = nums1[position];

        return ans;
    }
};
