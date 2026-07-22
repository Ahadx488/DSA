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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        
        queue<pair<TreeNode*, pair<int,int>>> q; 
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int horizontal = it.second.second;

            nodes[vertical][horizontal].insert(node -> val);

            if(node -> left != nullptr) {
                q.push({node -> left, {vertical - 1, horizontal + 1}});
            }
            if(node -> right != nullptr) {
                q.push({node -> right, {vertical + 1, horizontal + 1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it: nodes){
            vector<int> col;
            for(auto x: it.second){
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(col);
        }
        return ans;


    }
};