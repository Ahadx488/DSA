class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        if(fullMask == 0)
            return 0;

        // best[r][c][mask] = maximum energy
        // with which we have reached this state
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        // {row, col, mask, energy}
        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int moves = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nr >= m ||
                       nc < 0 || nc >= n ||
                       classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Cannot move if no energy
                    if(currEnergy == 0)
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if(classroom[nr][nc] == 'L') {

                        int idx = id[nr][nc];

                        newMask |= (1 << idx);
                    }

                    // If this was the last litter,
                    // we don't need energy anymore.
                    if(newMask == fullMask)
                        return moves + 1;

                    // Reset
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // If energy becomes 0 and we're not on R,
                    // we cannot continue from here.
                    if(newEnergy == 0)
                        continue;

                    // Only keep the state if we reached it
                    // with MORE energy than before.
                    if(newEnergy > best[nr][nc][newMask]) {

                        best[nr][nc][newMask] = newEnergy;

                        q.push({
                            nr,
                            nc,
                            newMask,
                            newEnergy
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};