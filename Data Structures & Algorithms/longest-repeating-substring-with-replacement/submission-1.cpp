class Solution {
public:
    int getMaxFreqCount (map<char,int> &frequencyCountMp) {
        int maxFreq = 0;
        for (auto it:frequencyCountMp) maxFreq = max (maxFreq, it.second);
        return maxFreq;

    }
    int characterReplacement(string s, int k) {
        map<char,int> frequencyCountMp;
        int left = 0, right = 0, maxAns = 0;
        while (right < s.length()) {
            frequencyCountMp[s[right]]++;
            int maxFreqCount = getMaxFreqCount (frequencyCountMp);
            while (right < s.length() && (right - left + 1 ) - maxFreqCount > k) {
                frequencyCountMp[s[left]]--;
                if (frequencyCountMp[s[left]] <= 0 ) frequencyCountMp.erase(s[left]);
                left++;
                maxFreqCount = getMaxFreqCount (frequencyCountMp);
            }
            maxAns = max (maxAns, right - left + 1);
            right++;
        }
        return maxAns;
    }
};