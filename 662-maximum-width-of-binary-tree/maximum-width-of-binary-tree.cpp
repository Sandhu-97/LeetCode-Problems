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

typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while (!q.empty()){
            int size = q.size();
            ll first = q.front().second;
            ll last = 0;

            for (int i=0;i<size;i++){
                auto [node, idx] = q.front(); q.pop();

                ll cur = idx-first;
                last = cur;

                if (node->left) q.push({node->left, 2*cur+1});
                if (node->right) q.push({node->right, 2*cur+2});
            }

            ans = max(ans, last+1);
        }
        return ans;
    }
};