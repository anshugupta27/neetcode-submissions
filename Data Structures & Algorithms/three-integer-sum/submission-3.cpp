class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sumFinal;
        int size = nums.size();
        for (int fixedPtr = 0; fixedPtr < size; fixedPtr++) {
            if (fixedPtr > 0  && nums[fixedPtr] == nums[fixedPtr - 1])
                continue;
            int fixedVal = nums[fixedPtr];

            int leftPtr = fixedPtr + 1, rightPtr = size - 1;
            int targetSum = -fixedVal;
            while (leftPtr < rightPtr) {
                if (nums[leftPtr] + nums[rightPtr] == targetSum) {
                    sumFinal.push_back(
                        {fixedVal, nums[leftPtr], nums[rightPtr]});
                    leftPtr++;
                    rightPtr--;
                    while (leftPtr < rightPtr &&
                           nums[leftPtr] == nums[leftPtr - 1])
                        leftPtr++;
                    while (rightPtr > leftPtr &&
                           nums[rightPtr] == nums[rightPtr + 1])
                        rightPtr--;
                } else if (nums[leftPtr] + nums[rightPtr] > targetSum) {
                    rightPtr--;
                } else
                    leftPtr++;
            }
        }
        return sumFinal;
    }
};