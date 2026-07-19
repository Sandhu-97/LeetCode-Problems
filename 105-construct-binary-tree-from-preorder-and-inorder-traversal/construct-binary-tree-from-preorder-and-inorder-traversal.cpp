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
    unordered_map<int, int> mp;
    int index=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(0, inorder.size()-1, preorder);
    }
    TreeNode* build(int start, int end, vector<int>& preorder){
        if (start>end) return nullptr;
        int rootval = preorder[index++];
        TreeNode* root = new TreeNode(rootval);
        int mid = mp[rootval];

        root->left = build(start, mid-1, preorder);
        root->right = build(mid+1, end, preorder);
        return root;
    }
    
};