class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> prefixLen (nums.size(), 1);
        int ans = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            int potentialAns = 1;
            for (int j = 0 ; j < i ; j++) {
                if (nums[i] > nums[j]) {
                    potentialAns = max(potentialAns, prefixLen[j]+1);
                }
            }
            prefixLen[i] = potentialAns;
        }
        for (int i = 0 ; i < prefixLen. size() ; i++) {
            ans = max (ans, prefixLen[i]);
        }
        return ans;
    }
};