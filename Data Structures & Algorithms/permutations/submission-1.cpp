class Solution {
public:
    void permuteUtil (vector<int>& nums, int index, vector<vector<int>> &finalAns) {
        if (index >= nums.size()) {
            finalAns.push_back (nums);
            return;
        }
        for (int i = index ; i < nums.size() ; i++) {
            swap (nums[i], nums[index]);
            permuteUtil (nums, index+1, finalAns);
            swap(nums[i], nums[index]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalAns;
        permuteUtil (nums, 0, finalAns);
        return finalAns;
        
    }
};