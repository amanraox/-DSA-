class Solution {
public:
    int dp[51][51][101];
    int n, m, k;

    int solve(int len, int lisLen, int lar){
        if(len == n){
            if(lisLen == k) return 1;
            return 0;
        }

        if(dp[len][lisLen][lar] != -1) return dp[len][lisLen][lar];

        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(i > lar){
                ans += solve(len + 1, lisLen + 1, i);
            }else{
                ans += solve(len + 1, lisLen, lar);
            }

            ans = ans % 1000000007;
        }

        return dp[len][lisLen][lar] = ans;
    }
    
    int numOfArrays(int N, int M, int K) {
        memset(dp, -1, sizeof(dp));
        n = N; m = M; k = K;
        return solve(0, 0, 0);
    }
};