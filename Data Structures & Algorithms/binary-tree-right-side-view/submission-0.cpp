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
    void dfs(TreeNode* cur, int curDepth, int& furthestDepth, vector<int>& ans){
        if(cur == nullptr){
            return;
        }
        if(curDepth > furthestDepth){
            ans.push_back(cur->val);
            furthestDepth++;
        }
        dfs(cur->right, curDepth + 1, furthestDepth, ans);
        dfs(cur->left, curDepth + 1, furthestDepth, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int furthestDepth = 0;
        dfs(root, 1, furthestDepth, ans);
        return ans;
    }
};
