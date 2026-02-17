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
    typedef pair<int,int> p;
    p solve(TreeNode* root){
        if (!root) return {0, 0};
        p left = solve(root->left);
        p right = solve(root->right);

        int skip = max(left.first, left.second) + max(right.first, right.second);
        int rob = root->val + left.first + right.first;

        return {skip, rob};
    }
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};