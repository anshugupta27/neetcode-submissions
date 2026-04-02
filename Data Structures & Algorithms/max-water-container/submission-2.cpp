class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1, waterContainer = 0, maxWaterStored = 0;
        while (left < right) {
            if (heights[left] < heights[right]) {
                waterContainer = heights[left] * (right - left);
                left++;
            } else {
                waterContainer = heights[right] * (right - left);
                right--;
            }
            maxWaterStored = max (maxWaterStored, waterContainer);
        }
        return maxWaterStored;
    }
};