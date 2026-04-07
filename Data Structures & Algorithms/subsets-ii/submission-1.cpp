class Solution {
public:
    void combinationSum2 (vector<int>& candidates, int index, vector<int> &temp, vector<vector<int>> &finalAns) {

        if (index >= candidates.size()) {
            finalAns.push_back (temp);
            return ;
        }

            // take
                temp.push_back(candidates[index]);
                combinationSum2 (candidates, index+1, temp, finalAns);
                temp.pop_back();


        // dont take
        while (index + 1 < candidates.size() && candidates[index] == candidates[index+1]) index++;
        combinationSum2 (candidates, index+1, temp, finalAns);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        vector<vector<int>> finalAns;
        vector<int> temp;
        sort (candidates.begin(), candidates.end());
        combinationSum2 (candidates, 0, temp, finalAns);
        return finalAns;
    }
};