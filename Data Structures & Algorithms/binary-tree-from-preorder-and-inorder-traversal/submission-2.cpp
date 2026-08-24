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

#include <unordered_map>

class Solution {
    unordered_map<int, int> mp;
public:
    TreeNode* dfs(vector<int>& pre, int l, int r, int& pos){
        if(r < l){
            return nullptr;
        }
        TreeNode* node = new TreeNode(pre[pos]);
        int ind = mp[pre[pos]];
        pos++;
        node->left = dfs(pre, l, ind - 1, pos);
        node->right = dfs(pre, ind + 1, r, pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = dfs(preorder, 0, preorder.size() - 1, pos);
        return root;
    }
};
