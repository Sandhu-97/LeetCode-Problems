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
    void solve(TreeNode* root, int current, int& sum){
        if (!root) return;
        current = current*10+root->val;
        if (!root->left && !root->right){
            sum+=current;
        }

        solve(root->left, current, sum);
        solve(root->right, current, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};