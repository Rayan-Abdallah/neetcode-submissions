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
 #include <string>
 #include <optional>

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string ans = "";
        std::function<void(TreeNode*)> dfs;
        dfs = [&](TreeNode* node){
            if(node == nullptr){
                ans += 'n';
                return;
            }
            ans += to_string(node->val);
            ans += 'l';
            dfs(node->left);
            ans += 'r';
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }

    int strToNum(int& ind, string& s){
        int res = 0;
        if(ind < s.size()){
            bool flip = 0;
            if(s[ind] == '-'){
                flip = 1;
                ind++;
            }
            res = (s[ind] - '0');
            ind++;
            if(flip){
                res *= -1;
            }
        } 
        while(ind < s.size() && isdigit(s[ind])){
            res *= 10;
            res += (s[ind] - '0');
            ind++;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        int ind = 0;
        TreeNode* root = new TreeNode(strToNum(ind, data));
        std::function<void(int&, TreeNode*)> dfs;
        dfs = [&](int& i, TreeNode* cur){
            if(data[i] == 'l'){
                i++;
                if(data[i] == 'n'){
                    cur->left = nullptr;
                    i++;
                }
                else{
                    cur->left = new TreeNode(strToNum(i, data));
                    dfs(i, cur->left);
                }
            }
            if(data[i] == 'r'){
                i++;
                if(data[i] == 'n'){
                    cur->right = nullptr;
                    i++;
                }
                else{
                    cur->right = new TreeNode(strToNum(i, data));
                    dfs(i, cur->right);
                }
            }
        };
        dfs(ind, root);
        return root;
    }
};
