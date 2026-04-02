class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0;
        map <char, int> countOfCharMp;
        while (right < s.length()) {
            if (countOfCharMp.find(s[right]) != countOfCharMp.end()) {
                if (countOfCharMp[s[right]] >= left) {
                    left = countOfCharMp[s[right]] + 1;
                }
            }
            maxLen = max (maxLen, right - left + 1);
            countOfCharMp[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};