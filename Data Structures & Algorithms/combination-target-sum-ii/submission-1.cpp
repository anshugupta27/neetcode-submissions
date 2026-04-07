class Solution {
public:
    void combinationSum2 (vector<int>& candidates, int target, int index, vector<int> &temp, vector<vector<int>> &finalAns) {
        if (target == 0) {
            finalAns.push_back (temp);
            return;
        }
        if (index >= candidates.size() || target < 0) return;

            // take
                temp.push_back(candidates[index]);
                combinationSum2 (candidates, target-candidates[index], index+1, temp, finalAns);
                temp.pop_back();


        // dont take
        while (index + 1 < candidates.size() && candidates[index] == candidates[index+1]) index++;
        combinationSum2 (candidates, target, index+1, temp, finalAns);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> finalAns;
        vector<int> temp;
        sort (candidates.begin(), candidates.end());
        combinationSum2 (candidates, target, 0, temp, finalAns);
        return finalAns;
    }
};