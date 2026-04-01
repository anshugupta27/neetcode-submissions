class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& waterFlow) {
        int totalRow = heights.size(), totalCol = heights[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol || waterFlow[row][col] != 0) return false;
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        int noWater = 0, singleOcean = 1, bothOcean = 2;
        vector<vector<int>> waterFlowPacific (row, vector<int>(col, noWater));
        vector<vector<int>> waterFlowAtlantic (row, vector<int>(col, noWater));
        queue<vector<int>> pacificQueue, atlanticQueue;
        vector<vector<int>> finalAns;
        
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (row_itr == 0 || col_itr == 0) {
                    waterFlowPacific[row_itr][col_itr]++;
                    pacificQueue.push({row_itr, col_itr});
                }
            }
        }
        while (pacificQueue.size()) {
            auto front = pacificQueue.front();
            pacificQueue.pop();
            int parentRow = front[0];
            int parentCol = front[1];
            for (int i = 0 ; i < 4 ; i++) {
                int childRow = parentRow + dx[i];
                int childCol = parentCol + dy[i];
                if (isValid(childRow, childCol, heights, waterFlowPacific) && heights[childRow][childCol] >= heights[parentRow][parentCol]) {
                    pacificQueue.push({childRow, childCol});
                    waterFlowPacific[childRow][childCol] = singleOcean;
                }
            }
        }
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (row_itr == row-1 || col_itr == col-1) {
                    waterFlowAtlantic[row_itr][col_itr]++;
                    atlanticQueue.push({row_itr, col_itr});
                }
            }
        }
        while (atlanticQueue.size()) {
            auto front = atlanticQueue.front();
            atlanticQueue.pop();
            int parentRow = front[0];
            int parentCol = front[1];
            for (int i = 0 ; i < 4 ; i++) {
                int childRow = parentRow + dx[i];
                int childCol = parentCol + dy[i];
                if (isValid(childRow, childCol, heights, waterFlowAtlantic) && heights[childRow][childCol] >= heights[parentRow][parentCol]) {
                    atlanticQueue.push({childRow, childCol});
                    waterFlowAtlantic[childRow][childCol]++;
                }
            }
        }
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                cout << waterFlowPacific[row_itr][col_itr] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if ( waterFlowAtlantic[row_itr][col_itr] && waterFlowPacific[row_itr][col_itr]) {
                    finalAns.push_back({row_itr, col_itr});
                }
            }
            cout << "\n";
        }

        return finalAns;

    }
};
