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
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2==0) return {};
        if (n==1) return {new TreeNode(0)};

        if (mp.count(n)) return mp[n];

        vector<TreeNode*> res;

        for(int left=1;left<=n-1;left+=2){
            int right = n-1-left;
            auto leftTree = allPossibleFBT(left);
            auto rightTree = allPossibleFBT(right);

            for (auto l: leftTree){
                for (auto r: rightTree){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return mp[n] = res;
    }
};