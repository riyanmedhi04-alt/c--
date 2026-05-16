class Solution {
public:
    // to check if any other prev queen is attacking our current queen ->
    bool isSafe(int row, int col, vector<string> &board, int n){
        // checking for the previous columns in the same row.
        for(int i = 0; i<col; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        // checking for upper triangle from the current.
        for(int i = row, j = col; i>= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // checking for lower triangle from the current
        for(int i = row, j = col; i<n && j>= 0; i++, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // checking rows are handled already since the current queen placed is the only queen in the entire column.
        return true;
    }
    // solveQueen func ->
    void solveQueen(int col, vector<vector<string>> &ans,vector<string> &board, int n){
        // if col no. == n - push the board (vector of strings) to ans and return.
        if(col == n){
            ans.push_back(board);
            return;
        }
        // for each row we are going to check with isSafe function and if safe then turn taht particular character of the string in board vector to 'Q'.
        for(int i = 0; i<n; i++){
            if(isSafe(i, col , board, n)){
                board[i][col] = 'Q';
                // recursive call for next column ->
                solveQueen(col+1, ans, board, n);
                // backtracking and again set the modified character to '.' for checking other posibilities from this position.
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string (n, '.'));
        solveQueen(0, ans, board, n);
        return ans;
    }
};
