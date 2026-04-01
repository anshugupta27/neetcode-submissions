class Solution {
public:
    void visitedConnectedComponentsDfs (vector<vector<int>> &adj, vector<int> &visited, int start) {
        visited[start] = 1;
        for (auto it : adj[start]) {
            if (!visited[it]) {
                visitedConnectedComponentsDfs (adj, visited, it);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        int component = 0;
        for (int itr = 0 ; itr < edges.size() ; itr++) {
            int firstNode = edges[itr][0];
            int secondNode = edges[itr][1];
            adj[firstNode].push_back(secondNode);
            adj[secondNode].push_back(firstNode);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                component++;
                visitedConnectedComponentsDfs (adj, visited, i);
            }
        }
        return component;
    }
};