class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> divisor(nums.size());

        for(int i=0; i < nums.size(); i++){
            for (int j=1; j*j <= nums[i] ; j++){
                if (nums[i] % j == 0 ){
                    divisor[i].push_back(j);
                    if (nums[i] / j != j ){
                        divisor[i].push_back(nums[i]/j);
                }
                }
            }
        }

        for (int i=0; i < divisor.size(); i++){
            if (divisor[i].size() == 4)
                ans = ans + divisor[i][0] + divisor[i][1] + divisor[i][2] + divisor[i][3];
        }

        return ans;

    }
};