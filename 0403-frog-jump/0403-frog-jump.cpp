class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n+1,false));
        dp[0][0] = true;
    
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int k=stones[i] -stones[j];
                if(k > j+1) break;
                dp[i][k] = dp[j][k-1] or dp[j][k] or dp[j][k+1];
                if(i==n-1 and dp[i][k]) return 1;
            }
        }
        return false; 
    }
};