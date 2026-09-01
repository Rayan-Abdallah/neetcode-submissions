class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        for(int i = 0; i < 1 << nums.size(); i++){
            int x = i;
            vector<int> temp;
            int ind = 0;
            while(x > 0){
                if(x%2){
                    temp.push_back(nums[ind]);
                }
                x/=2;
                ind++;
            }
            res.push_back(temp);
        }
        return res;
    }
};
