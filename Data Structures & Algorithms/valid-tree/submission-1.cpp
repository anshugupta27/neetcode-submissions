class Solution {
public:
    bool visitNodes (int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                if(!visitNodes (it, node, adj, visited)) return false;
            } else if (it != parent) return false;
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // cycle detection in undirected graph
        vector<int> visited (edges.size()+10, 0);
        vector<vector<int>> adj (edges.size()+10);
        int graphCount = 0;
        for (int itr = 0 ; itr < edges.size() ; itr++) {
            int firstNode = edges[itr][0];
            int secondNode = edges[itr][1];
            adj[firstNode].push_back(secondNode);
            adj[secondNode].push_back(firstNode);
        }
        for (auto it = 0 ; it < n ; it++) {
            if (!visited[it]) {
                graphCount++;
                if(!visitNodes (it, -1, adj, visited)) return false;
            }
        }
        if (graphCount > 1) return false;
        return true;
    }
};