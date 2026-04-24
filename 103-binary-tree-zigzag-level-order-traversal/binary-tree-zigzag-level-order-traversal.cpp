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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        int count=1;
        while (!q.empty()){
            int size=q.size();
            vector<int> curr;
            while (size--){
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                curr.push_back(node->val);
            }

            if (count % 2 == 0){
                reverse(curr.begin(), curr.end());
            }

            ans.push_back(curr);
            count++;
        }
        return ans;

    }
};