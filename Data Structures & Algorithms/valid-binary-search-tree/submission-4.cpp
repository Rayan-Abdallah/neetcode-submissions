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
    bool ans = true;
    pair<int, int> dfs(TreeNode* curNode){
        int left = curNode->val, right = curNode->val;
        if(curNode->left != nullptr){
            auto leftSide = dfs(curNode->left);
            if(curNode->val <= leftSide.second){
                ans = false;
            }
            left = min(left, leftSide.first);
            right = max(right, leftSide.second);
        }
        if(curNode->right != nullptr){
            auto rightSide = dfs(curNode->right);
            if(curNode->val >= rightSide.first){
                ans = false;
            }
            left = min(left, rightSide.first);
            right = max(right, rightSide.second);
        }
        return {left, right};
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
