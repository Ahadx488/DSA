class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0 );
        
        vector<vector<int>> reverseGraph(n);

        for(int i = 0; i < n; i++){
            for(auto it: graph[i]){
                reverseGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> result;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto it: reverseGraph[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};