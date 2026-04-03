class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push('a');
        for (int i = 0 ; i < s.length() ;i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            else {
                if (stk.size() && s[i] == ')' && stk.top() != '(') return false;
                if (stk.size() && s[i] == '}' && stk.top() != '{') return false;
                if (stk.size() && s[i] == ']' && stk.top() != '[') return false;
                stk.pop();
            }
        }
        return stk.size() > 1 ? false : true;

    }
};