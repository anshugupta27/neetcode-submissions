class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], tempSum = nums[0];
        for (int i = 1 ; i < nums.size() ; i++) {
            tempSum = max (nums[i], tempSum+nums[i]);
            maxSum = max (maxSum, tempSum);
        }
        return maxSum;
    }
};