class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> distance(m,  vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;

            for(int i = 0; i < 4; i++){ 
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && mat[nr][nc] == 1 ){
                    vis[nr][nc] = 1;
                    q.push({{nr ,nc}, d + 1});
                    distance[nr][nc] = d + 1;
                }

            }
        }
        return distance;
    }
};