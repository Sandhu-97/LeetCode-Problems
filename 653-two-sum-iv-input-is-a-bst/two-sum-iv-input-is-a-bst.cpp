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

    void inorder(TreeNode* root, vector<int>& ans){
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        int i=0;
        int j=ans.size()-1;

        while (i<j){
            int s = ans[i]+ans[j];
            if (s==k) return true;
            else if (s<k) i++;
            else j--;
        }
        return false;
    }
};