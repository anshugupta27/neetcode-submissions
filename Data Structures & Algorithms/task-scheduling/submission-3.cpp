class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for (int i = 0 ;  i < tasks.size() ; i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }
        int time = 0;
        while (pq.size()) {
            vector<int> temp;
            int executed = 0;
            for (int i = 0 ; i <= n ; i++) {
                if(!pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    if (top > 1) temp.push_back(top-1);
                    executed++;
                }
                
            }
            for (int i = 0 ; i < temp.size() ; i++) {
                pq.push(temp[i]);
            }
            time += pq.empty() ? executed : n+1;
        }
        return time;
    }
};