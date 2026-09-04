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
private:
    void dfs(TreeNode* cur, int mx, int& ans){
        if(cur == nullptr){
            return;
        }
        mx = max(mx, cur->val);
        if(cur->val >= mx){
            ans++;
        }
        dfs(cur->left, mx, ans);
        dfs(cur->right, mx, ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, -101, ans);
        return ans;
    }
};
