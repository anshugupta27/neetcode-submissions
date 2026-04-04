class Solution {
public:
    vector<int> partitionLabels(string s) {
        map <char, pair<int, int>> mp;
        vector<vector<int>> vec;
        for (int i = 0 ; i < s.length() ; i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second = i;
            } else {
                mp[s[i]].first = i;
                mp[s[i]].second = i;
            }
        }
        for (auto it : mp) {
            vec.push_back ({it.second.first, it.second.second});
        }
        sort(vec.begin(), vec.end());
        int minVal = vec[0][0], maxVal = vec[0][1];
        vector<int> ans;
        for (int i = 1 ; i < vec.size() ; i++) {
            if (vec[i][0] >= minVal && vec[i][0] <= maxVal) {
                minVal = min (minVal, vec[i][0]);
                maxVal = max (maxVal, vec[i][1]);
            } else {
                ans.push_back (maxVal-minVal+1);
                minVal = vec[i][0], maxVal = vec[i][1];
            }
        }
        ans.push_back (maxVal-minVal+1);
        return ans;
        
    }
};
