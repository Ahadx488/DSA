class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        //vec.push_back({row - row0, col - col0});
        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr, nc, vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        // set<vector<pair<int, int>>> st;
        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    //vector<pair<int, int>> vec;
                    //dfs(i, j, vis, vec, grid, i, j);
                    dfs(i, j, vis, grid);
                    cnt++;
                    //st.insert(vec);
                }
            }
        }

        //return st.size();
        return cnt;
    }
};