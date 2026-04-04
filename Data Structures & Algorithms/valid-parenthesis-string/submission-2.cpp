class Solution {
public:
    bool checkValidString(string s) {
        int minPar = 0, maxPar = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(') {
                minPar++;
                maxPar++;
            } else if (s[i] == ')') {
                minPar--;
                maxPar--;
            } else {
                minPar--;
                maxPar++;
            }
            
            if (maxPar < 0) return false;
            else if (minPar < 0) minPar = 0;
        }
        return minPar == 0;
    }
};