class Solution {
public:
    bool checkIfCycle (vector<vector<int>> &adj, vector<int> &visited, int start, int parent) {
        visited[start] = 1;
        for (auto it : adj[start]) {
            if (!visited[it]) {
                if(checkIfCycle (adj, visited, it, start)) return true;
            } else if (it != parent) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // keep adding one edge at a time and keep checking if you find a cycle in the graph 
        // as soon as you find a cycle that edge is the one that should be removed
        vector<vector<int>> adj(edges.size()+10);
        for (int i = 0 ; i < edges.size() ; i++) {
            vector<int> visited (edges.size()+10, 0);
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(checkIfCycle (adj, visited, a, -1)) return {a,b};
            
        }
        return {};
    }
};