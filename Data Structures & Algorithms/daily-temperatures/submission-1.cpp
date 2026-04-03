class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // greater to the right
        stack<int> stk;
        vector<int> finalAns;
        int n = temperatures.size();
        for (int i = n-1 ; i >= 0 ; i--) {
            if (stk.empty()) finalAns.push_back (0);
            else if (stk.size() && temperatures[stk.top()] > temperatures[i]) finalAns.push_back (stk.top() - i);
            else {
                while (stk.size() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
                if (stk.size() && temperatures[stk.top()] > temperatures[i]) finalAns.push_back (stk.top() - i);
                else finalAns.push_back (0);
            }
            stk.push(i);
        }
        reverse(finalAns.begin(), finalAns.end());
        return  finalAns;
    }
};