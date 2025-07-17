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
    int findMax(TreeNode* root, int currentMax){
        while (root){
            currentMax = max(currentMax, root->val);
            root = root->right;
        }
        return currentMax;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL){
            return NULL;
        }

        if (root->val<key) root->right = deleteNode(root->right, key);
        else if (root->val>key) root->left = deleteNode(root->left, key);
        else{
            if (root->left != NULL && root->right != NULL){
                int v = findMax(root->left, INT_MIN);
                root->val=v;
                root->left = deleteNode(root->left, v);
            }
            else if (!root->left) return root->right;
            else if (!root->right) return root->left;
        }
        return root;
    }
};