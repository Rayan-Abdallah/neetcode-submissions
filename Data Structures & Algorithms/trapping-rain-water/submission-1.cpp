class Solution {
private:
    int n;
    int left_fill(int r, vector<int>& height, vector<pair<int, int>>& pref){
        if(r == 0){
            return 0;
        }
        pair<int, int> p = pref[r - 1];
        int edge = min(p.first, height[r]);
        int sum = 0;
        for(int i = p.second + 1; i < r; i++){
            sum += max(0, (edge - height[i]));
        }
        return sum + left_fill(p.second, height, pref);
    }
    int right_fill(int l, vector<int>& height, vector<pair<int, int>>& suff){
        if(l == n - 1){
            return 0;
        }
        pair<int, int> p = suff[l + 1];
        int edge = min(p.first, height[l]);
        int sum = 0;
        for(int i = l + 1; i < p.second; i++){
            sum += max(0, (edge - height[i]));
        }
        return sum + right_fill(p.second, height, suff);
    }
public:
    int trap(vector<int>& height) {
        n = height.size();
        if(n == 1){
            return 0;
        }
        vector<pair<int, int> > pref(n, {0, 0}), suff(n, {0, n - 1});
        int h = 0, ind = 0;
        for(int i = 0; i < n - 1; i++){
            if(height[i] >= height[i + 1] && (!i || height[i] >= height[i -1])){
                if(height[i] > h){
                    h = height[i];
                    ind = i;
                }
            }
            pref[i] = {h, ind};
        }
        if(height[n - 1] >= h){
            h = height[n - 1];
            ind = n - 1;
        }
        pref[n - 1] = {h, ind};
        h = 0, ind = n - 1;
        for(int i = n - 1; i > 0; i--){
            if(height[i] >= height[i - 1] && 
            ((i == n - 1) || height[i] >= height[i + 1])){
                if(height[i] >= h){
                    h = height[i];
                    ind = i;
                }
            }
            suff[i] = {h, ind};
        }
        if(height[0] >= h){
            h = height[0];
            ind = 0;
        }
        suff[0] = {h, ind};
        pair<int, int> start = suff[0];
        return left_fill(start.second, height, pref) 
        + right_fill(start.second, height, suff);
    }
};
