class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, potentialMinAns = INT_MAX;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[low] <= nums[mid]) {
                potentialMinAns = min (potentialMinAns, nums[low]);
                low = mid + 1;
            } else {
                potentialMinAns = min (potentialMinAns, nums[mid]);
                high = mid - 1;
            }
        }
        return potentialMinAns;
    }
};