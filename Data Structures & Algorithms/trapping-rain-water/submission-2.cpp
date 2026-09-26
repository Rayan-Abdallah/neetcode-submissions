class Solution {
private:
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1){
            return 0;
        }
        vector<int> pref(n), suff(n);
        int h = 0;
        for(int i = 0; i < n; i++){
            h = max(h, height[i]);
            pref[i] = h;
        }
        h = 0;
        for(int i = n - 1; i >= 0; i--){
            h = max(h, height[i]);
            suff[i] = h;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (max(0, (min(pref[i], suff[i]) - height[i])));
        }
        return ans;
    }
};
