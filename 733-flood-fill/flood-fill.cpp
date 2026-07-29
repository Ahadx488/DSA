class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] ==  color) return image;
        
        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && image[nr][nc] == image[sr][sc]){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]){
                    image[i][j] = color;
                }
            }
        }
        return image;
    }
};