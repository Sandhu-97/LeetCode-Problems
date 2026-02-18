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
    int max_depth, ans;
    void solve(TreeNode* root, int depth){
        if (!root) return;

        if (depth>max_depth){
            max_depth = depth;
            ans = root->val;
        }

        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        max_depth = -1, ans =0;
        solve(root, 0);
        return ans;
    }
};