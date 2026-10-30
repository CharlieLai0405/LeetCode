#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int ans = arr1.size();
        for (int i = 0; i < arr1.size(); i++)
        {
            int left = 0;
            int right = arr2.size();
            int right_num = arr1[i] + d;
            int left_num = arr1[i] - d;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (arr2[mid] > right_num)
                    right = mid;
                else if (arr2[mid] <= right_num && arr2[mid] >= left_num)
                {
                    ans--;
                    break;
                }
                else
                    left = mid + 1;
            }
        }
        return ans;
    }
};