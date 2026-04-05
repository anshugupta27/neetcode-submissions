class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort starttime wise so normal sorting
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> finalInterval;
        vector<int> prevInterval = intervals[0];
        int i = 1;
        while (i < intervals.size()) {
            if (prevInterval[1] >= intervals[i][0]) {
                prevInterval[0] = min (prevInterval[0], intervals[i][0]);
                prevInterval[1] = max (prevInterval[1], intervals[i][1]);
            } else {
                finalInterval.push_back (prevInterval);
                prevInterval = intervals[i];
            }
            i++;
        }
        finalInterval.push_back(prevInterval);
        return finalInterval;
    }
};