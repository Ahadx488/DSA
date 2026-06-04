class Solution {
public:

    vector<TreeNode*> build(int start, int end) {

        if(start > end) {
            return {nullptr};
        }

        vector<TreeNode*> ans;

        for(int rootVal = start; rootVal <= end; rootVal++) {

            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            for(auto left : leftTrees) {
                for(auto right : rightTrees) {

                    TreeNode* root = new TreeNode(rootVal);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};