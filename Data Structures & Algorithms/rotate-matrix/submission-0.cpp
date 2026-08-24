class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - i - 1; j++){
                    int temp[4] = {matrix[i][j], matrix[i + (j - i)][n - i - 1],
                    matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]};
                    matrix[i][j] = temp[3];
                    matrix[i + (j - i)][n - i - 1] = temp[0];
                    matrix[n - i - 1][n - j - 1] = temp[1];
                    matrix[n - j - 1][i] = temp[2];
            }
        }
    }
};
