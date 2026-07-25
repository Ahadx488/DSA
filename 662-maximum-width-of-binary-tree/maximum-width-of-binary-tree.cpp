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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(!q.empty()){
            int n = q.size();
            int minInd = q.front().second;

            int first = 0;
            int last = 0;

            for(int i = 0; i < n; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int idx = it.second - minInd;

                if(i == 0)first = idx;
                if(i == n - 1)last = idx;
                // first = min(first, idx - minInd);
                // last = max(last , idx - minInd);

                if(node -> left != nullptr) q.push({node -> left, 2LL*idx + 1});
                if(node -> right !=  nullptr) q.push({node -> right, 2LL*idx + 2});


            }
            maxWidth = max(maxWidth , last - first +1);
        }
        return maxWidth;
    }
};