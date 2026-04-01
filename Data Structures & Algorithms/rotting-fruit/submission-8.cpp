class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid (int row, int col, vector<vector<int>>& grid) {
        int totalRow = grid.size(), totalCol = grid[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol) return false;
        return true;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> rottenOrangesQueue;
        int row = grid.size(), col = grid[0].size(), rottenOrange = 2, freshOrange = 1;
        int timeToRot = 0;
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (grid[row_itr][col_itr] == rottenOrange) {
                    rottenOrangesQueue.push({row_itr, col_itr});
                }
            }
        }
        while (rottenOrangesQueue.size()) {
            int size = rottenOrangesQueue.size();
            while (size--) {
                auto front = rottenOrangesQueue.front();
                rottenOrangesQueue.pop();
                int rottenParentRow = front[0];
                int rottenParentCol = front[1];
                for (int dir = 0 ; dir < 4 ; dir++) {
                    int childRow = rottenParentRow + dx[dir];
                    int childCol = rottenParentCol + dy[dir];
                    if (isValid (childRow, childCol, grid) && grid[childRow][childCol] == freshOrange) {
                        rottenOrangesQueue.push({childRow, childCol});
                        grid[childRow][childCol] = rottenOrange;
                        grid[childRow][childCol] = 2;
                    }
                }
            }
            timeToRot++;
        }
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (grid[row_itr][col_itr] == freshOrange) {
                    return -1;
                }
            }
        }
        return timeToRot-1 == -1 ? 0 : timeToRot-1;
    }
};
