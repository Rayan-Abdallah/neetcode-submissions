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
    int ans = -1000;
    int maxPath(TreeNode* cur){
        if(cur == nullptr){
            return 0;
        }
        int sumOfLeft = maxPath(cur->left);
        int sumOfRight = maxPath(cur->right);
        int curPath = max(cur->val, cur->val + max(sumOfLeft, sumOfRight));
        ans = max(ans, max(curPath, cur->val + sumOfLeft + sumOfRight));
        return curPath;
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }
};
