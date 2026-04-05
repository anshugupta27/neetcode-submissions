/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start_time;
        vector<int> end_time;
        for (int i = 0 ; i < intervals.size() ; i++) {
            start_time.push_back(intervals[i].start);
            end_time.push_back(intervals[i].end);
        }
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());
        int startPtr = 0, endPtr = 0, tempRoomReq = 0, maxRoomRequired = 0;
        while (startPtr < start_time.size() && endPtr < end_time.size()) {
            if (start_time[startPtr] < end_time[endPtr]) {
                tempRoomReq++;
                startPtr++;
            } else {
                tempRoomReq--;
                endPtr++;
            }
            maxRoomRequired = max(tempRoomReq, maxRoomRequired);
        }
        return maxRoomRequired;
        
    }
};
