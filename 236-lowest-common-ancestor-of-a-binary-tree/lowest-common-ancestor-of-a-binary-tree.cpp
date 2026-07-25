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
    // bool getPath(TreeNode* root, vector<TreeNode*> &arr, int t){
    //     if(root == nullptr ) return false;

    //     arr.push_back(root);
    //     if(root -> val == t) return true;

    //     if(getPath(root -> left, arr, t) || getPath(root -> right, arr, t)) return true;

    //     arr.pop_back();
    //     return false;
    // }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == nullptr) return nullptr;
        // vector<TreeNode*> ans1;
        // vector<TreeNode*> ans2;

        // getPath(root, ans1, p -> val);
        // getPath(root, ans2, q -> val);
        // int n = min(ans1.size(), ans2.size());
        // TreeNode* ans = nullptr;
        // for(int i = 0; i < n; i++){
        //     if(ans1[i] == ans2[i]) {
        //         ans = ans1[i];
        //     }
        // }

        // return ans;

        if(root == nullptr || p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left == nullptr) return right;
        else if(right == nullptr) return left;

        else{
            return root;
        }

    }
};