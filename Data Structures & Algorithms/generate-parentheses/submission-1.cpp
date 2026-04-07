class Solution {
public:
    void generateParenthesisUtil (int n, int opening, int closing, string ans, vector<string> &finalAns) {
        if (opening == closing && opening + closing == 2 *n ) {
            finalAns.push_back(ans);
            return;
        }
        if (opening > n || closing > n) return;
        if (opening >= closing) {
            generateParenthesisUtil (n, opening+1, closing, ans + '(', finalAns);
        } 
        if (opening > closing) {
            generateParenthesisUtil (n, opening, closing+1, ans + ')', finalAns);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> finalAns;
        generateParenthesisUtil (n, 0, 0, "", finalAns);
        return finalAns;
    }
};

// 1. opening == closing - always oepning afterwards

// 2. opening > closing - both can be done 

// 3. opening < closing - bad case return back

// 4. opening == closing && opening + closing == 2*n -> stop condition