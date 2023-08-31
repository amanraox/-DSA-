class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, 0);

        for(int i = 0; i <= n ; i++){
            if(ranges[i]== 0) continue;
            int left = max(0 , i - ranges[i]);
            dp[left] = max(dp[left], i + ranges[i]);
        }

        int last = 0;
        int maxDistance = 0;
        int taps = 0;

        for(int j = 0; j <= n; ++j){
            if(j > last){
                if(maxDistance <= last) return -1;

                last = maxDistance;
                ++taps;
            }
            maxDistance = max(maxDistance, dp[j]);
        }

        if(last < n){
            return taps + 1;
        }
        return taps;
    }
};