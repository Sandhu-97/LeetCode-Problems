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

    void solve(TreeNode* root, string& res){
        if (root==nullptr) return;

        res+=to_string(root->val);

        if (root->left || root->right){
            res+="(";
            solve(root->left, res);
            res+=")";
        }
        if (root->right){
            res+="(";
            solve(root->right ,res);
            res+=")";
        }
        
    }
    string tree2str(TreeNode* root) {
        string ans;
        solve(root, ans);
        return ans;
    }
};