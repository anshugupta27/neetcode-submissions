class Solution {
public:
    void combinationSumUtil (vector<int>& candidates, int target, int index, vector<int>&temp, vector<vector<int>> &finalAns) {
        if (target == 0) {
            finalAns.push_back(temp);
            return;
        }
        if (index >= candidates.size()) {
            return;
        }
        if (target >= candidates[index]) {
            // take it
            temp.push_back(candidates[index]);
            combinationSumUtil (candidates, target-candidates[index], index, temp, finalAns);
            temp.pop_back();
        }
        // dont take
        combinationSumUtil (candidates, target, index+1, temp, finalAns);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> finalAns;
        combinationSumUtil (candidates, target, 0, temp, finalAns);
        return finalAns;

    }
};