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
    bool ans = false;
    void solve(TreeNode* root, int sum, int target){
        if (!root) return;
        sum += root->val;
        if (sum==target && !root->left && !root->right){
            ans = true;
            return;
        }

        if (!ans && root->left) solve(root->left, sum, target);
        if (!ans && root->right) solve(root->right, sum, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root, 0, targetSum);
        return ans;
    }
};