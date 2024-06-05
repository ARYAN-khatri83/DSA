class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            // row check
            if (board[row][i] == val) {
                return false;
            }
            // col check
            if (board[i][col] == val) {
                return false;
            }
            // 3*3 matrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board) {
        int n = board.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                // cell empty
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(row, col, board, val)) {
                            board[row][col] = val;
                            // recursive call
                            bool solutionPossible = solveSudokuHelper(board);
                            if (solutionPossible) {
                                return true;
                            } else {
                                // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
