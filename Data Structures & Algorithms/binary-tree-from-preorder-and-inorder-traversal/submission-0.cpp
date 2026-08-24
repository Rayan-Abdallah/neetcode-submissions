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
    TreeNode* dfs(vector<int>& pre, vector<int> in, int l, int r, int& pos){ // pos for pre
        if(r < l){
            return nullptr;
        }
        TreeNode* node = new TreeNode(pre[pos]);
        for(int i = l; i <= r; i++){
            if(pre[pos] == in[i]){
                pos++;
                node->left = dfs(pre, in, l, i - 1, pos);
                node->right = dfs(pre, in, i + 1, r, pos);
                break;
            }
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        TreeNode* root = dfs(preorder, inorder, 0, preorder.size() - 1, pos);
        return root;
    }
};
