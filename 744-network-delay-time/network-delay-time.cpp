class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto edge: times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> q;

        q.push({0, k});
        dist[k] = 0;
        while(!q.empty()){
            auto it = q.top();
            q.pop();

            int time = it.first;
            int node = it.second;

            if(time > dist[node]) continue;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                
                if(time + edgeWt < dist[adjNode]){
                    dist[adjNode] = time + edgeWt;
                    q.push({dist[adjNode], adjNode});
                }
                
            }
        }
        int delay = INT_MIN;
        for(int i = 1;i <= n; i++){
            if(dist[i] == 1e9) return -1;
            delay = max(delay, dist[i]);
        }
        return delay;
    }
};