class Solution {
public:
    vector<int> getSmallestOnLeft (vector<int>& heights) {
        int totalBuildings = heights.size();
        stack<int> stack;
        vector<int> smallestOnLeft;

        for (int i = 0 ; i < totalBuildings ; i++) {
            if (stack.empty()) smallestOnLeft.push_back(-1);
            else if (stack.size() && heights[stack.top()] < heights[i]) smallestOnLeft.push_back (stack.top());
            else {
                while (stack.size() && heights[stack.top()] >= heights[i]) stack.pop();
                if (stack.empty()) smallestOnLeft.push_back(-1);
                else smallestOnLeft.push_back(stack.top());
            }
            stack.push(i);
        }
        return smallestOnLeft;
    }
    vector<int> getSmallestOnRight (vector<int>& heights) {
        int totalBuildings = heights.size();
        stack<int> stack;
        vector<int> smallestOnRight;
        for (int i = totalBuildings - 1 ; i >= 0 ; i--) {
            if (stack.empty()) smallestOnRight.push_back (totalBuildings);
            else if (stack.size() && heights[stack.top()] < heights[i] ) smallestOnRight.push_back (stack.top());
            else {
                while (stack.size() && heights[stack.top()] >= heights[i]) stack.pop();
                if (stack.empty()) smallestOnRight.push_back(totalBuildings);
                else smallestOnRight.push_back (stack.top());
            }
            stack.push(i);
        }
        reverse (smallestOnRight.begin(), smallestOnRight.end());
        return smallestOnRight;
    }
    int largestRectangleArea(vector<int>& heights) {
        // smallest on the left - store the idnex
        // smallest on the right - store the index
        // current height * width
        vector<int> smallestOnLeft = getSmallestOnLeft (heights);
        vector<int> smallestOnRight = getSmallestOnRight (heights);
        int totalBuildings = heights.size(), maxArea = 0;
        for (int i = 0 ; i < totalBuildings ; i++) {
            int length = heights[i];
            int width = abs(smallestOnRight[i] - smallestOnLeft[i]) - 1;
            maxArea = max (maxArea, length*width);
        }
        return maxArea;



    }
};