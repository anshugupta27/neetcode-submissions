class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> freqMapT;
        for (int i = 0 ; i < t.length() ; i++) {
            freqMapT[t[i]]++;
        }
        int uniqueElementT = freqMapT.size();
        for (int i = 0 ; i < s.length() ; i++) {
            freqMapT[s[i]]--;
            if (freqMapT[s[i]] == 0) uniqueElementT--;
            else if (freqMapT[s[i]] < 0) return false;
        }
        return uniqueElementT == 0;
    }
};