class Solution {
public:
    const int mod = 1e9 + 7;
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                dp[i][j]=dp[i - 1][j - 1]*(n - j + 1)%mod; //new song
                if (j > k) {
                    dp[i][j]+=dp[i - 1][j]*(j - k); //repeated 
                    dp[i][j]%=mod;
                }
            }
        }

        return dp[goal][n];
    }
};