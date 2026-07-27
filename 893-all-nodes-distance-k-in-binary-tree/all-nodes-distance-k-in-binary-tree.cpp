/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void store_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp) {
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(node -> left != nullptr){
                q.push(node -> left);
                mpp[node -> left] = node;
            }

            if(node -> right != nullptr){ 
                q.push(node -> right);
                mpp[node -> right] = node;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        store_parents(root, mpp);
        queue<TreeNode*> bfs;
        bfs.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target ] = true;
        int dis = 0;
        while(!bfs.empty()){
            
            int n = bfs.size();
            
            if(dis == k) break;
            dis++;

            for(int i = 0; i < n; i++){
                auto node = bfs.front();
                bfs.pop();
                if(node -> left != nullptr && !vis[node -> left]){
                    bfs.push(node -> left);
                    vis[node -> left] = true;
                }
                if(node -> right != nullptr && !vis[node -> right]){
                    bfs.push(node -> right);
                    vis[node -> right] = true;
                }
                TreeNode* parent = mpp[node];
                if(parent != nullptr && !vis[parent]){
                    bfs.push(parent);
                    vis[parent] = true;
                }
            }
        }

        vector<int> result;
        while(!bfs.empty()) {
            auto it = bfs.front();
            bfs.pop();
            result.push_back(it -> val);
        }

        return result;
    }
};