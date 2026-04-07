class Solution {
public:
    void isValidPalindrome (int leftDir, int rightDir, string s, int &palindrome) {
        while (leftDir >= 0 && rightDir < s.length()) {
            if (s[leftDir] != s[rightDir]) return;
            palindrome++;
            leftDir--, rightDir++;
        }
        return;

    }
    int countSubstrings(string s) {
        int palindrome = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            isValidPalindrome (i, i, s, palindrome);
            isValidPalindrome (i, i+1, s, palindrome);
        }
        return palindrome;
    }
};