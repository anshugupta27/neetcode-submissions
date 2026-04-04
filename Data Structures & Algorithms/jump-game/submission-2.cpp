class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndexItCanReach = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (maxIndexItCanReach < i) return false;
            maxIndexItCanReach = max (maxIndexItCanReach, nums[i] + i);
            
        }
        return true;
    }
};