class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> mp;

        // Check rows
        for (int i = 0; i < 9; i++) {
            mp.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                if (mp.count(board[i][j]))
                    return false;

                mp.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            mp.clear();
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;

                if (mp.count(board[i][j]))
                    return false;

                mp.insert(board[i][j]);
            }
        }

        // Check 3x3 subgrids
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                mp.clear();

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {

                        if (board[i][j] == '.')
                            continue;

                        if (mp.count(board[i][j]))
                            return false;

                        mp.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};