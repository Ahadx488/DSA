class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            int nodes = 0;
            int noOfEdges = 0;

            while(!q.empty()) {
                auto node = q.front();
                q.pop();
                //vis[node] = 1;
                nodes++;
                noOfEdges += adjList[node].size();
                for(auto it: adjList[node]) {
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }

            noOfEdges /= 2;
            if(noOfEdges == (nodes * (nodes - 1))/2) ans++;
        }
        return ans;
    }
};