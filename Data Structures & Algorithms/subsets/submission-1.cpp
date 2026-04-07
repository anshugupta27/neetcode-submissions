class Solution {
public:
    void subsetsUtil (vector<int>& nums, int index, vector<int> &temp, vector<vector<int>> &finalAns) {
        if (index == nums.size()) {
            finalAns.push_back(temp);
            return ;
        }
        // take
        temp.push_back(nums[index]);
        subsetsUtil (nums, index+1, temp, finalAns);
        temp.pop_back();
        // dont take
        subsetsUtil (nums, index+1, temp, finalAns);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> finalAns;
        subsetsUtil (nums, 0, temp, finalAns);
        return finalAns;
    }
};