class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i =  0 ;
        vector<vector<int>> finalInterval;
        // before insertion of intrevals
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            finalInterval.push_back(intervals[i]);
            i++;
        }

        // insertion or overlap
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min (newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        finalInterval.push_back({newInterval[0], newInterval[1]});


        // after insertion
        while (i < intervals.size()) {
            finalInterval.push_back(intervals[i]);
            i++;
        }
        return finalInterval;
        
    }
};