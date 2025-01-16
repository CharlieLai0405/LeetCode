#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> toBinary(int num) {
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

    int countOne(vector<int> num) {
        int count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == 1) {
                count++;
            }
        }
        return count;
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

    int minimizeXor(int num1, int num2) {
        int ans = 0;
        int temp1 = num1;
        int temp2 = num2;

        vector<int> num_1 = toBinary(num1);
        vector<int> num_2 = toBinary(num2);

        int num1_one = countOne(num_1);
        int num2_one = countOne(num_2);

        bool check = true;

        if (num_1.size() > num_2.size())
            check = false;

        if (num_1.size() < num_2.size()) {
            int temp = num_2.size() - num_1.size();
            for (int i = 0; i < temp; i++)
                num_1.insert(num_1.begin(), 0);
        }

        if (num1_one == num2_one) {
            return ans = num1;
        }
        else if (num2_one == num_2.size()) {
            if (check)
                return ans = num2;
            else {
                if (num1_one > num2_one) {
                    for (int i = 0; i < num_1.size(); i++) {
                        if (num_1[i] == 1 && num2_one != 0) {
                            num2_one--;
                        }
                        else if (num_1[i] == 1 && num2_one == 0) {
                            num_1[i] = 0;
                        }
                    }
                }
                else {
                    num2_one = num2_one - num1_one;
                    for (int i = num_1.size() - 1; i != 0 && num2_one != 0;
                        i--) {
                        if (num_1[i] == 0) {
                            num_1[i] = 1;
                            num2_one--;
                        }
                    }
                }
            }
        }
        else if (num1_one > num2_one) {
            for (int i = 0; i < num_1.size(); i++) {
                if (num_1[i] == 1 && num2_one != 0) {
                    num2_one--;
                }
                else if (num_1[i] == 1 && num2_one == 0) {
                    num_1[i] = 0;
                }
            }
        }
        else // num1_one < num2_one
        {
            num2_one = num2_one - num1_one;
            int rem = num2_one;
            for (int i = num_1.size() - 1; i != 0 && num2_one != 0; i--) {
                if (num_1[i] == 0) {
                    num_1[i] = 1;
                    num2_one--;
                }
            }
        }

        ans = toTen(num_1);

        return ans;
    }
};
