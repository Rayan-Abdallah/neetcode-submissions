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
    vector<char> pathOfP;
    vector<char> pathOfQ;

    bool dfs(TreeNode* curNode, int target, bool isP){
        if(curNode == nullptr){
            return false;
        }
        if(curNode->val == target){
            return true;
        }
        bool leftPath = dfs(curNode->left, target, isP);
        bool rightPath = dfs(curNode->right, target, isP);
        vector<char>* addTo = isP ? &pathOfP : &pathOfQ;
        if(leftPath){
            (*addTo).push_back('l');
        }
        else if(rightPath){
            (*addTo).push_back('r');
        }
        else{
            return false;
        }
        return true;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, true);
        dfs(root, q->val, false);
        reverse(pathOfP.begin(), pathOfP.end());
        reverse(pathOfQ.begin(), pathOfQ.end());
        TreeNode* lca = root;
        int ind = 0;
        while(ind < min(pathOfP.size(), pathOfQ.size())
         && pathOfP[ind] == pathOfQ[ind]){
            if(pathOfP[ind] == 'l'){
                lca = lca->left;
            }
            else{
                lca = lca->right;
            }
            ind++;
         }
         return lca;
    }
};
