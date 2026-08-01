class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int> > freqToVal;
        int arr[4005] = {0};
        for(int i = 0; i < nums.size(); i++){
            arr[2000 + nums[i]]++;
        }
        for(int i = 1000; i<=3000; i++){
            if(arr[i] != 0){
                freqToVal.push_back({arr[i], i - 2000});
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
