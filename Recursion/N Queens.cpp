class Solution {
public:
    // Convert the board into the required format and add it to the results
    void addSolution(vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
        vector<string> temp; // to store the current solution in the required format
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    row += 'Q';
                } else {
                    row += '.';
                }
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        int x = row;
        int y = col;

        // Check for same row
        while (y >= 0) {
            if (board[x][y] == 1) return false;
            y--;
        }

        // Check for upper diagonal on the left side
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) return false;
            x--;
            y--;
        }

        // Check for lower diagonal on the left side
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true;
    }

    void ToSolve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        // Base case: all queens are placed
        if (col == n) {
            addSolution(board, ans, n);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // If placing queen is safe
                board[row][col] = 1;
                ToSolve(col + 1, ans, board, n);
                // Backtrack
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        ToSolve(0, ans, board, n); // Start solving from the first column
        return ans;
    }
};
