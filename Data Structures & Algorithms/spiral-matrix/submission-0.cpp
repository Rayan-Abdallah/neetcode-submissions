class Solution {
public:
    void traverse(vector<vector<int> >& matrix, int step, vector<int>& res, int cnt){
        int n = matrix.size(), m = matrix[0].size(), full = m * n;
        if(cnt == full){
            return;
        }
        for(int i = step; i < m - step; i++){
            res.push_back(matrix[step][i]);
        }
        cnt += (m - step*2);
        if(cnt == full){
            return;
        }
        for(int i = step + 1; i < n - step; i++){
            res.push_back(matrix[i][m - step - 1]);
        }
        cnt += (n - 2*step - 1);
        if(cnt == full){
            return;
        }
        for(int i = m - step - 2; i >= step; i--){
            res.push_back(matrix[n - step - 1][i]);
        }
        cnt += (m - 2*step - 1);
        if(cnt == full){
            return;
        }
        for(int i = n - step - 2; i > step; i--){
            res.push_back(matrix[i][step]);
        }
        cnt += (n - 2*step - 2);
        traverse(matrix, step + 1, res, cnt);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        traverse(matrix, 0, ans, 0);
        return ans;
    }
};
