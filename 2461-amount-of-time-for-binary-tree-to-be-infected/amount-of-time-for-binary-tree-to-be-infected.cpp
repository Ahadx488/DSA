/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* preorder(TreeNode* root , int start) {
        if(root == nullptr) return nullptr;

        if(root -> val == start) return root;
        TreeNode* left = preorder(root -> left, start);
        if(left) return left;
        return preorder(root -> right, start);
    }
    void store_parents(TreeNode*root , unordered_map<TreeNode*, TreeNode*> &parents){
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if(node -> left != nullptr){
                q.push(node -> left);
                parents[node -> left] = node;
            }
            if(node -> right != nullptr){
                q.push(node -> right);
                parents[node -> right] = node;
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(root == nullptr) return 0;
        TreeNode* Start = preorder(root, start);
        if(Start == nullptr) return 0;
        unordered_map<TreeNode*, TreeNode*> parents;
        store_parents(root, parents);
        
        queue<TreeNode*> bfs;
        bfs.push(Start);
        unordered_map<TreeNode*, bool> vis;
        vis[Start] = true;
        int time = 0;

        while(!bfs.empty()){
            int n = bfs.size();
            //time++;

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
                
                auto it = parents.find(node);
                if(it != parents.end() && !vis[it -> second]) {
                    bfs.push(it -> second);
                    vis[it -> second] = true;
                }
            }
            time++;
        }
        return time -1 ;
    }
};