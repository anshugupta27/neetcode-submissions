class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &visited) {
        int totalRow = grid.size(), totalCol = grid[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol || visited[row][col] || grid[row][col] == 0) return false;
        return true;
    }

    void findAreaOfIslandDfs (vector<vector<int>>& grid, vector<vector<int>> &visited, int row, int col, int &countIslandSize) {
        visited[row][col] = 1;
        countIslandSize++;
        for (int dir = 0 ; dir < 4 ; dir++) {
            int childRow = row + dx[dir];
            int childCol = col + dy[dir];
            if (isValid(childRow, childCol, grid, visited)) {
                findAreaOfIslandDfs (grid, visited, childRow, childCol, countIslandSize);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visited (row, vector<int> (col, 0));
        
        int maxArea = 0;
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                int countIslandSize = 0;
                if (!visited[row_itr][col_itr] && grid[row_itr][col_itr] == 1) {
                    findAreaOfIslandDfs (grid, visited, row_itr, col_itr, countIslandSize);
                    maxArea = max (maxArea, countIslandSize);
                }
            }
        }
        return maxArea;

    }
};
