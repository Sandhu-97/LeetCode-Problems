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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});

        while (!q.empty()){
            int size = q.size();
            int parent1=-1, parent2=-1;
            bool foundx=false,foundy=false;
            for (int i=0;i<size;i++){
                auto [node, parent] = q.front(); q.pop();

                if (node->val==x) {
                    parent1=parent;
                    foundx=true;
                }
                if (node->val==y) {
                    parent2=parent;
                    foundy=true;
                }

                if (node->left) q.push({node->left, node->val});
                if (node->right) q.push({node->right, node->val});
            }

            if (foundx && foundy && parent1!=parent2) return true;
            else if (foundx && foundy) return false;

        }
        return false;
    }
};