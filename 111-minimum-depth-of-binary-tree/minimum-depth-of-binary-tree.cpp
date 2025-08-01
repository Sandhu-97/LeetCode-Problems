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
    void solve(TreeNode* root, int level, int& ans){
        if (!root) return;
        if (!root->left && !root->right){
            ans = min(ans, level);
            return;
        }

        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ans=INT_MAX;
        solve(root, 1, ans);
        return ans;
    }
};