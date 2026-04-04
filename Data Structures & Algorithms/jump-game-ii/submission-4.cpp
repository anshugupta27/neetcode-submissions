class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, left = 0, right = 0;
        while (right < nums.size()-1) {
            int farthestJump = 0;
            for (int i = left ; i <= right ; i++) {
                farthestJump = max (farthestJump, i + nums[i]);
            }
            left = right + 1;
            right = farthestJump;
            jumps++;
        }
        return jumps;
        
    }
};