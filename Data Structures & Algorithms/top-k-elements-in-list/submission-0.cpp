class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int> > freqToVal;
        int arr[2005] = {0};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                arr[1000 + (nums[i]*-1)]++;
            }
            else{
                arr[nums[i]]++;
            }
        }
        for(int i = 0; i<=1000; i++){
            if(arr[i] != 0){
                freqToVal.push_back({arr[i], i});
            }
        }
        for(int i = 1001; i <= 2000; i++){
            if(arr[i] != 0){
                freqToVal.push_back({arr[i], (i - 1000)*-1});
            }
        }
        sort(freqToVal.begin(), freqToVal.end());
        vector<int> ans;
        for(int i = freqToVal.size() - k; i < freqToVal.size(); i++){
            ans.push_back(freqToVal[i].second);
        }
        return ans;
    }
};
