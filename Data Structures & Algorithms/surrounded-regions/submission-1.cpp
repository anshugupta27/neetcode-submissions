class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    bool isValid(int row, int col, vector<vector<char>>& board) {
        int totalRow = board.size(), totalCol = board[0].size();
        if (row < 0 || row >= totalRow || col < 0 || col >= totalCol || board[row][col] != 'O') return false;
        return true;

    }
    void solve(vector<vector<char>>& board) {
        // first push al those zeros that are on the edge 
        // then visit all the zeros that are connected with the zeros in the queue
        // after that re iterate the matrix and turn the real zeros that are left to X and turn back the earlier queue zeros to zero again 

        queue<vector<int>> borderCoonectZerosQueue;
        int row = board.size(), col = board[0].size();
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if ((row_itr == 0 || row_itr == row-1 || col_itr == 0 || col_itr == col-1) && board[row_itr][col_itr] == 'O') {
                    borderCoonectZerosQueue.push({row_itr, col_itr});
                    board[row_itr][col_itr] = '1';
                }
            }
        }
        while (borderCoonectZerosQueue.size()) {
            auto front = borderCoonectZerosQueue.front();
            borderCoonectZerosQueue.pop();
            int parentRow = front[0];
            int parentCol = front[1];
            for (int i = 0 ; i < 4 ; i++) {
                int childRow = parentRow + dx[i];
                int childCol = parentCol + dy[i];
                if (isValid(childRow, childCol, board)) {
                    borderCoonectZerosQueue.push({childRow, childCol});
                    board[childRow][childCol] = '1';
                }
            }
        }
        for (int row_itr = 0 ; row_itr < row ; row_itr++) {
            for (int col_itr = 0 ; col_itr < col ; col_itr++) {
                if (board[row_itr][col_itr] == 'O') {
                    board[row_itr][col_itr] = 'X';
                }
                else if (board[row_itr][col_itr] == '1') board[row_itr][col_itr] = 'O';
            }
        }
    }
};