class Solution {
public:
    int countNeighbour(int r, int c, vector<vector<int>>& board) {
        int val = 0;
        for (int i = r - 1; i <= r + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if (i == r && j == c)
                    continue;
                if (i < 0 || j < 0 || i >= board.size() ||
                    j >= board[0].size()) {
                    continue;
                } else if (board[i][j] == 3 || board[i][j] == 1) {
                    val += 1;
                }
            }
        }
        return val;
    }

    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {
                int val = countNeighbour(i, j, board);

                if (board[i][j] == 1 && (val < 2 || val > 3)) {
                    board[i][j] = 3;
                } else if (val == 3 && board[i][j]==0) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};