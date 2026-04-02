class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = (matrix.size()*matrix[0].size())-1, row = matrix.size(), col = matrix[0].size();
        while (low <= high) {
            int mid = low + (high - low)/2;
            int midRow = mid/col, midCol = mid%col;
            if (matrix[midRow][midCol] == target) return true;
            else if (matrix[midRow][midCol] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};