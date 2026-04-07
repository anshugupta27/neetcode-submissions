class Solution {
public:
    vector<int> getMinDelay (vector<vector<vector<int>>> &adj, int k, int n) {
        queue<pair<int,int>> q;
        q.push({k, 0});
        vector<int> distance (n + 1, INT_MAX);
        distance[k] = 0; 
        while (q.size()) {
            auto front = q.front();
            q.pop();
            int parentNode = front.first;
            int parentDistance = front.second;
            for (auto it : adj[parentNode]) {
                int childNode = it[0];
                int childDistance = it[1];
                if (parentDistance + childDistance < distance[childNode]) {
                    distance[childNode] = parentDistance + childDistance;
                    q.push({childNode, distance[childNode]});
                }
            }
        }
        return distance;

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj (n+1);
        for (int i = 0 ;  i < times.size() ; i++) {
            auto ele = times[i];
            int start = ele[0];
            int end = ele[1];
            int time = ele[2];
            adj[start].push_back ({end, time});
        }
        int maxDistance = -1;
        vector<int> distance = getMinDelay (adj, k, n);
        for (int i = 1 ; i < distance.size() ; i++) {
            if (distance[i] > maxDistance) {
                maxDistance = distance[i];
            }
            if (distance[i] == INT_MAX) return -1;
        }
        return maxDistance;
    }
};