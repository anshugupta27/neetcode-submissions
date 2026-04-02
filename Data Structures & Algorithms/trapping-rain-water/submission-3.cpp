class Solution {
public:
    int trap(vector<int>& heights) {
        // max from left
        // max from right 
        // min of both 
        // sub the min from current height 
        // sum all those values 
        vector<int> maxFromLeft (heights.size(), 0);
        vector<int> maxFromRight (heights.size(), 0);
        maxFromLeft[0] = heights[0];
        maxFromRight[heights.size()-1] = heights[heights.size()-1];
        int waterOccupied = 0;

        for (int i = 1 ; i < heights.size() ; i++) {
            maxFromLeft [i] = max(heights[i], maxFromLeft[i-1]);
        }
         for (int i = heights.size()-2 ; i >= 0 ; i--) {
            maxFromRight [i] = max(heights[i], maxFromRight[i+1]);
        }
        for (int i = 0 ; i < heights.size() ; i++) {
           waterOccupied += min (maxFromLeft[i], maxFromRight[i]) - heights[i];
        }
        return waterOccupied;
    }
};