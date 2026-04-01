class Solution {
public:
    bool scheduleCourseDfs (vector<vector<int>>& adj, vector<int> &visited, vector<bool>&pathVisited, int start) {
        visited[start] = 1;
        pathVisited[start] = true;
        for (auto it:adj[start]) {
            if (!visited[it]) {
                if(!scheduleCourseDfs (adj, visited, pathVisited, it)) return false;
            } else if (pathVisited[it]) return false;
        }
        pathVisited[start] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // to finish all the courses you should not have loop in the graph
        // a <- b
        // draw an undirected graph
        vector<vector<int>> adj(numCourses);
        vector<int> visited (numCourses, 0);
        vector<bool> pathVisited (numCourses, false);
        for (int itr = 0 ; itr < prerequisites.size() ; itr++) {
            int firstTask = prerequisites[itr][1];
            int secondTask = prerequisites[itr][0];
            adj[firstTask].push_back(secondTask);
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!visited[i])
            if(!scheduleCourseDfs (adj, visited, pathVisited, i)) return false;
        }
        return true;
        
    }
};