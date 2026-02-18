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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()){
            int size = q.size();
            int check = size-1;
            while (size--){
                auto front = q.front(); q.pop();
                if (check==size) ans = front->val;
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        return ans;
    }
};