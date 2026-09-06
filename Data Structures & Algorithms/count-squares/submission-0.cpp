#include <cstring>

class CountSquares {
int cnt[1005][1005]{};
public:
    CountSquares() {
        memset(cnt, 0, sizeof(cnt));
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for(int i = 0; i < x; i++){
            int dist = x - i;
            if(dist + y <= 1000){
                if(cnt[i][y] && cnt[i][dist + y] && cnt[x][dist + y]){
                    ans += (cnt[i][y] * cnt[i][dist + y] * cnt[x][dist + y]);
                }
            }
            if(y - dist >= 0){
                if(cnt[i][y] && cnt[i][y - dist] && cnt[x][y - dist]){
                    ans += (cnt[i][y] * cnt[i][y - dist] * cnt[x][y - dist]);
                }
            }
        }
        for(int i = x + 1; i <= 1000; i++){
            int dist = i - x;
            if(dist + y <= 1000){
                if(cnt[i][y] && cnt[i][dist + y] && cnt[x][dist + y]){
                    ans += (cnt[i][y] * cnt[i][dist + y] * cnt[x][dist + y]);
                }
            }
            if(y - dist >= 0){
                if(cnt[i][y] && cnt[i][y - dist] && cnt[x][y - dist]){
                    ans += (cnt[i][y] * cnt[i][y - dist] * cnt[x][y - dist]);
                }
            }
        }
        return ans;
    }
};
