class Solution {
public:
    bool isValidDecodedString (int start, int end, string s) {
        if (end-start+1 > 2) return false;
        if (s[start] == '0') return false;
        if (end - start + 1 == 2) {
            string temp = s.substr(start, end-start+1);
            int num = stoi(temp);
            if (num > 26) return false;
        }
        return true;

    }
    int numDecodingsUtil (string s, int start, vector<int>&dp) {
        if (start >= s.length()) {
            return 1;
        }
        if (dp[start] != -1) return dp[start];
        int ans = 0;
        for (int i = start ; i < s.length() ; i++) {
            if (isValidDecodedString (start, i, s)) {
                ans += numDecodingsUtil (s, i+1, dp);
            } 
        }
        return dp[start] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp (s.length(), -1);
        int validDecodedSubstring = 0;
        return numDecodingsUtil (s, 0, dp);
    }
};