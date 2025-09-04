class Solution {
public:
    int findClosest(int x, int y, int z) {
        int ans = 0;
        int dis_x = abs(x - z);
        int dis_y = abs(y - z);
        if (dis_x < dis_y)
            ans = 1;
        if (dis_x > dis_y)
            ans = 2;
        return ans;
    }
};