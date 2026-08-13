class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> pos[26];
        for(int i = 0; i < text1.size(); i++){
            pos[text1[i] - 'a'].push_back(i);
        }
        int stopped[26] = {0};
        vector<int> dp;
        int longest = 0;
        for(int i = 0; i < text2.size(); i++){
            int charVal = text2[i] - 'a';
            if(stopped[charVal] < pos[charVal].size()){
                int posInd = pos[charVal][stopped[charVal]];
                stopped[charVal]++;
                if(!longest || dp[longest - 1] < posInd){
                    dp.push_back(posInd);
                    longest++;
                    continue;
                }
                bool endHere = false;
                int origLast = dp[longest - 1];
                int l = 0, r = longest - 1;
                int replaceInd = 0;
                while(l <= r){
                    int mid = l + (r - l) / 2;
                    if(dp[mid] > posInd){
                        replaceInd = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                stopped[text1[dp[replaceInd]] - 'a']--;
                dp[replaceInd] = posInd;
                auto it = upper_bound(pos[charVal].begin(), pos[charVal].end(), origLast);
                if(it != pos[charVal].end()){
                    longest++;
                    dp.push_back(*it);
                }
            }
        }
        return longest;
    }
};
