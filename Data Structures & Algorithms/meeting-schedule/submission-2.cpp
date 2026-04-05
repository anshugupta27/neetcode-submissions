class Solution {
public:
    static bool comp (Interval &a, Interval &b) {
        if (a.end == b.end) return a.start < b.start;
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int prev = 0, count = 0;
        if(intervals.size() == 0) return true;
        for (int next = 1 ; next < intervals.size() ; next++) {
            if (intervals[next].start >= intervals[prev].end) {
                prev = next;
                count++;
            }
        }
        cout <<  intervals.size() << ", " << count;
        return intervals.size() == count+1;

        
    }
};