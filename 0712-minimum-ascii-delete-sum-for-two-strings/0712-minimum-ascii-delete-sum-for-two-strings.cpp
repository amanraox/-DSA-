class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum =0;
        for(auto&i:s1)sum+=i;
        for(auto&i:s2)sum+=i;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i = s1.length()-1; i>=0; i--){
            for(int j = s2.length()-1; j>=0; j--){
                if(s2[j]==s1[i])dp[i][j]=s2[j]+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return sum-2*dp[0][0];
    }
};