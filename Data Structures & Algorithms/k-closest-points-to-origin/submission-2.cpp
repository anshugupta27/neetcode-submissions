class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<int>> finalAns;
        for (int i = 0 ; i < points.size() ; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int distance = (x1*x1) + (y1*y1);
            minHeap.push({distance, x1, y1});
        }
        while (k--) {
            finalAns.push_back({minHeap.top()[1], minHeap.top()[2]});
            minHeap.pop();
        }
        return finalAns;

    }
};