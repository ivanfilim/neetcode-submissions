class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<set<char>> rows(n);
        vector<set<char>> columns(n);
        map<pair<int, int>, set<char>> squares;
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i].find(board[i][j]) != rows[i].end()) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                if (columns[j].find(board[i][j]) != columns[j].end()) {
                    return false;
                }
                columns[j].insert(board[i][j]);
                pair<int, int> p(i / 3, j / 3);
                if (squares.find(p) == squares.end()) {
                    squares[p] = set<char>();
                } else if (squares[p].find(board[i][j]) != squares[p].end()) {
                    return false;
                }
                squares[p].insert(board[i][j]);
            }
        }

        return true;
    }
};
