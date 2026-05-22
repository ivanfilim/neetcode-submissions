class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        map<int, set<char>> rows;
        map<int, set<char>> columns;
        map<int, set<char>> squares;

        for (int i = 0; i < n; ++i) {
            rows[i] = set<char>();
            columns[i] = set<char>();
            squares[i] = set<char>();
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int squares_idx = 3 * (i / 3) + (j / 3);
                if (rows[i].find(board[i][j]) != rows[i].end() ||
                    columns[j].find(board[i][j]) != columns[j].end() ||
                    squares[squares_idx].find(board[i][j]) != squares[squares_idx].end()) 
                    return false;
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                squares[squares_idx].insert(board[i][j]);
            }
        }

        return true;
    }
};
