class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> isValidPair (triplets.size(), true);
        bool firstIndexFound = false, secondIndexFound = false, thirdIndexFound = false;
        for (int i = 0 ; i < triplets.size() ; i++) {
            vector<int> potentialAns = triplets[i];
            if (potentialAns[0] > target[0] || potentialAns[1] > target[1] || potentialAns[2] > target[2])
            isValidPair[i] = false;
        }
        for (int i = 0 ; i < isValidPair.size() ; i++) {
            if (isValidPair[i] == true) {
                vector<int> potentialAns = triplets[i];
                if (potentialAns[0] == target[0]) firstIndexFound = true;
                if (potentialAns[1] == target[1]) secondIndexFound = true;
                if (potentialAns[2] == target[2]) thirdIndexFound = true;
            }
        }
        if (firstIndexFound && secondIndexFound && thirdIndexFound) return true;
        return false;
    }
};