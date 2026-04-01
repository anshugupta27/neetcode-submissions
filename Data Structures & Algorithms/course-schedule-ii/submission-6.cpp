class Solution {
public:
    bool scheduleCourseDfs (vector<vector<int>>  &adj, vector<int> &visited, vector<int> &pathVisited, stack<int> &pathSequence, int start) {
        visited[start] = 1;
        pathVisited[start] = 1;
        for (auto it: adj[start]) {
            if (!visited[it]) {
                if(!scheduleCourseDfs (adj, visited, pathVisited, pathSequence, it)) return false;
            } else if (pathVisited[it]) return false;
        }
        pathVisited[start] = 0;
        pathSequence.push(start);
        return true;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited (numCourses, 0);
        vector<int> pathVisited (numCourses, 0);
        vector<int> finalSequence;
        stack<int> pathSequence;
        for (int itr = 0 ; itr < prerequisites.size() ; itr++) {
            int firstCourse = prerequisites[itr][1];
            int secondCourse = prerequisites[itr][0];
            adj[firstCourse].push_back(secondCourse);
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!visited[i]) {
                if(!scheduleCourseDfs (adj, visited, pathVisited, pathSequence, i)) return {};
            }
        }
        while (pathSequence.size()) {
            finalSequence.push_back(pathSequence.top());
            pathSequence.pop();
        }
        return finalSequence;
    }
};