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

    void solve(TreeNode* root, string path, vector<string>& res){
        if (!root) return;

        path+=to_string(root->val);

        if (!root->left && !root->right){
            res.push_back(path);
        }

        path+="->";
        solve(root->left, path, res);
        solve(root->right, path, res);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        solve(root, path, res);
        return res;
    }
};