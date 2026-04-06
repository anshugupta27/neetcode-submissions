class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int maxLen = 0;
        for (int i = 0 ; i < nums.size() ; i++) mp[nums[i]]++;
        for (auto it : mp) {
            if (mp.find(it.first-1) == mp.end()) {
                int start = it.first;
                while (mp.find(start) != mp.end()) {
                    start = start + 1;
                }
                maxLen = max (maxLen, start - it.first);
            }
        }
        return maxLen;
        
    }
};