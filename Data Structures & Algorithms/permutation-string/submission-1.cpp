class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // steps
        // 1. create map for freq occurences of s1
        // 2. take window size of s1.length
        // 3. iterate the window over the s2 and keeping updating the mapp if you get an element or remove from map if window moves out 
        // at a point when all the unique values varibale equals zero that the answer
        if (s2.length() < s1.length()) return false;
        map<char, int> freqS1Mp;
        for (int itr = 0 ; itr < s1.length() ; itr++) {
            freqS1Mp[s1[itr]]++;
        }
        int uniqueEle = freqS1Mp.size();
        int left = 0, right = 0;
        while (right < s1.length()) {
            if(freqS1Mp.find(s2[right]) != freqS1Mp.end() ) {
                freqS1Mp[s2[right]]--;
                if (freqS1Mp[s2[right]] == 0) uniqueEle--;
            }
            right++;
        }
        if (uniqueEle == 0) return true;
        while (right < s2.length()) {
            if(freqS1Mp.find(s2[right]) != freqS1Mp.end()) {
                freqS1Mp[s2[right]]--;
                if (freqS1Mp[s2[right]] == 0) uniqueEle--;
            }
            if (freqS1Mp.find(s2[left]) != freqS1Mp.end()) {
                freqS1Mp[s2[left]]++;
                if (freqS1Mp[s2[left]] == 1)
                uniqueEle++;
            }
            left++;
            right++;
            if (uniqueEle == 0) return true;
        }
        return false;
    }
};