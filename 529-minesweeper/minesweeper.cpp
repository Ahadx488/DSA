class Solution {
private:
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    void dfs(int r, int c, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int mines = 0;

        // Count adjacent mines
        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               board[nr][nc] == 'M') {
                mines++;
            }
        }

        // If adjacent mines exist, place digit
        if(mines > 0) {
            board[r][c] = mines + '0';
            return;
        }

        // Otherwise mark as blank
        board[r][c] = 'B';

        // Reveal neighbours
        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               board[nr][nc] == 'E') {
                dfs(nr, nc, board);
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int r = click[0];
        int c = click[1];

        if(board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(r, c, board);

        return board;
    }
};