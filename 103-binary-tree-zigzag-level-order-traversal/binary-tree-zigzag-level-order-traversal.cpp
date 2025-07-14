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
        if (!root) return ans;
        q.push(root);


        bool flag=false;
        while (!q.empty()){
            int size=  q.size();
            vector<int> temp;
            for (int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
             
            }
            if (flag) reverse(temp.begin(), temp.end());
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};