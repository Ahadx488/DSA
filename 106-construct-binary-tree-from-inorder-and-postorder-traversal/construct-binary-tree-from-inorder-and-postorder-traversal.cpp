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
    TreeNode* makeTree(vector<int> &inorder, int inStart, int inEnd, 
    vector<int> &postorder, int postStart, int postEnd, map<int,int> &mpp) {
        if(inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root -> val];
        int numsLeft = inRoot - inStart;
        
        root -> left = makeTree(inorder, inStart, inRoot - 1, postorder,
        postStart, postStart + numsLeft - 1, mpp);

        root -> right = makeTree(inorder, inRoot + 1, inEnd, postorder,
        postStart + numsLeft, postEnd - 1, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        int n = inorder.size();
        int m = postorder.size();

        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }

        return makeTree(inorder, 0, n - 1, postorder, 0, m - 1, mpp);
    }
};