class Solution {
public:
    bool isValidSubString(int start, int end, string s,  vector<string>& wordDict) {
        string temp = s.substr(start, end-start+1);
        for (int i = 0 ; i < wordDict.size() ; i++) {
            if (temp == wordDict[i]) return true;
        }
        return false;
    }

    bool wordBreakUtil (string s, int start, vector<string>& wordDict, vector<int> &dp) {
        if (start == s.length()) return true;
        if (dp[start] != -1) return dp[start];
        for (int i = start ; i < s.length() ; i++) {
            if (isValidSubString(start, i, s, wordDict)) {
                if(wordBreakUtil (s, i+1, wordDict, dp)) return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);
        return wordBreakUtil (s, 0, wordDict, dp);
    }
};