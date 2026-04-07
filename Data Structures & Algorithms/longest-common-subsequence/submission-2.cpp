class Solution {
public:
    int longestCommonSubsequenceUtil (string text1, string text2, int index1, int index2, vector<vector<int>> &dp) {
        if (index1 >= text1.length() || index2 >= text2.length()) return dp[index1][index2] = 0;
        int ans1 = 0, ans2 = 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if (text1[index1] == text2[index2]) {
            ans1 = 1 + longestCommonSubsequenceUtil (text1, text2, index1+1, index2+1, dp);
        } else {
            ans2 = max (longestCommonSubsequenceUtil (text1, text2, index1+1, index2, dp), longestCommonSubsequenceUtil (text1, text2, index1, index2+1, dp));
        }
        return dp[index1][index2] = max (ans1, ans2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.length()+1, vector<int>(text2.length()+1, -1));
        return longestCommonSubsequenceUtil (text1, text2, 0, 0, dp);
    }
};