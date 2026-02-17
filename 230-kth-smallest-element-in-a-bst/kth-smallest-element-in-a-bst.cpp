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
    int ans, K;
    void solve(TreeNode* root){
        if (!root) return;

        solve(root->left);
        K--;
        if (K==0){
            ans = root->val;
            return;
        }
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        solve(root);
        return ans;
    }
};