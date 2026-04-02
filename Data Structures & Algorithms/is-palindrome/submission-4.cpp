class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left <= right) {
            while (left < s.length() && !isalnum(s[left])) left++;
            while (right < s.length() && !isalnum(s[right])) right--;
            if (left < s.length() && right < s.length() && tolower(s[left]) != tolower(s[right])) return false;
            left++, right--;
        }
        return true;
    }
};