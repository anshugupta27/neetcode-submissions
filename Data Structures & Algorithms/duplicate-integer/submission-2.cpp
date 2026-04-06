class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> countFreqMp;
        for (int itr = 0 ; itr < nums.size() ; itr++) {
            if (countFreqMp.find(nums[itr]) != countFreqMp.end()) return true;
            countFreqMp[nums[itr]]++;
        }
        return false;
    }
};