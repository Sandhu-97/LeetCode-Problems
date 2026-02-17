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

    vector<int> solve(TreeNode* root){
        if (!root) return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        int skip = max(left[0], left[1]) + max(right[0], right[1]);
        int rob = root->val + left[0] + right[0];

        return {skip, rob};
    }
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans[0], ans[1]);
    }
};