class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowIsZero = false, firstColIsZero = false;
        for(int i = 0; i < matrix.size(); i++){
            if(!matrix[i][0]){
                firstColIsZero = 1;
            }
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if(!matrix[0][i]){
                firstRowIsZero = 1;
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(!matrix[i][j]){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(!matrix[0][j] || !matrix[i][0]){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(firstColIsZero){
                matrix[i][0] = 0;
            }
        }
        for(int i = 1; i < matrix[0].size(); i++){
            if(firstRowIsZero){
                matrix[0][i] = 0;
            }
        }
    }
};
