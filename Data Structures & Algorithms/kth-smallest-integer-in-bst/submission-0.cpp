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
    int subTreeSize[10005] = {0};
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        subTreeSize[node->val] = 1 + dfs(node->left) + dfs(node->right);
        return subTreeSize[node->val];
    }
    int findSmallest(TreeNode* node, int target){
        if(node == nullptr){
            return -1;
        }
        if(node->left == nullptr){
            if(target == 1){
                return node->val;
            }
            return findSmallest(node->right, target - 1);
        }
        if(node->right == nullptr){
            if(subTreeSize[node->left->val] + 1 == target){
                return node->val;
            }
            return findSmallest(node->left, target);
        }
        int sizeOfLeft = subTreeSize[node->val] - subTreeSize[node->right->val];
        if(sizeOfLeft == target){
            return node->val;
        }
        else if(sizeOfLeft < target){
            return findSmallest(node->right, target - sizeOfLeft);
        }
        return findSmallest(node->left, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return findSmallest(root, k);
    }
};
