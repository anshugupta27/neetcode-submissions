class Solution {
public:
    static bool comp (vector<int> &v1, vector<int> &v2) {
        if (v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> prevInterval = intervals[0];
        int i = 1, goodIntervals = 0;
        while (i < intervals.size()) {
            if (intervals[i][0] < prevInterval[1]) {
                i++;
            } else {
                goodIntervals++;
                prevInterval = intervals[i];
                i++;
            }
        }
        return intervals.size() - goodIntervals - 1;
    }
};