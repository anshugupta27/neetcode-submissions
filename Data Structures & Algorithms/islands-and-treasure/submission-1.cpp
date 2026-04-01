class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, vector<vector<int>>& grid) {
        int totalRow = grid.size(), totalCol = grid[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol || grid[row][col] != INT_MAX) return false;
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        // push all the treasure chest in queue then 
        // then find the distance of these chest treasures with the lands 
        // whenever you update a cell push it in the queue again so that the children can be updated again 

         int row = grid.size(), col = grid[0].size();
         queue<vector<int>> node_distance_queue;
         vector<vector<int>> distance (row, vector<int>(col, INT_MAX));

         for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (grid[row_itr][col_itr] == 0) {
                    node_distance_queue.push({row_itr, col_itr, 0});
                    distance[row_itr][col_itr] = 0;
                }
                if (grid[row_itr][col_itr] == -1) distance[row_itr][col_itr] = -1;
            }
         }
         while (node_distance_queue.size()) {
            auto queue_front = node_distance_queue.front();
            node_distance_queue.pop();
            int parentRow = queue_front[0];
            int parentCol = queue_front[1];
            int parentDistance = queue_front[2];
            for (int dir = 0 ; dir < 4 ; dir++) {
                int childRow = parentRow + dx[dir];
                int childCol = parentCol + dy[dir];
                if (isValid(childRow, childCol, grid) && parentDistance + 1 < distance[childRow][childCol]) {
                    distance[childRow][childCol] = parentDistance + 1;
                    node_distance_queue.push({childRow, childCol, parentDistance+1});
                }
            }
         }
         grid = distance;
    }
};
