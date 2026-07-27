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
    int findLeftHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int height = 0;
        while(root ){
            height++;
            root = root -> left;
        }
        return height;
    }
    int findRightHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int height = 0;
        while(root ){
            height++;
            root = root -> right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if(leftHeight == rightHeight){
            return (1 << rightHeight) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
        
    }
};