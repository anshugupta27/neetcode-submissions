class Solution {
public:
    void isValidPalindrome (int leftDir, int rightDir, string s, int &maxLen, int &startIndex, int &endIndex) {
        while (leftDir >= 0 && rightDir < s.length()) {
            if (s[leftDir] != s[rightDir]) {
                if (rightDir-leftDir-1 > maxLen) {
                    maxLen = rightDir-leftDir-1;
                    startIndex = leftDir+1, endIndex = rightDir-1;
                }
                return;
            }
            leftDir--, rightDir++;
        }
        if (rightDir-leftDir-1 > maxLen) {
                    maxLen = rightDir-leftDir-1;
                    startIndex = leftDir+1, endIndex = rightDir-1;
        }
        return;

    }
    string longestPalindrome(string s) {
        int maxLen = 0, startIndex = 0, endIndex = -1;
        for (int i = 0 ; i < s.length() ; i++) {
            isValidPalindrome (i, i, s, maxLen, startIndex, endIndex);
            isValidPalindrome (i, i+1, s, maxLen, startIndex, endIndex);
        }
        return s.substr(startIndex, endIndex-startIndex+1);
    }
};