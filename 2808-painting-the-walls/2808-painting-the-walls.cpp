class Solution {
public:
    int solve(int i,int t,vector<int>& cost,vector<int>& time,vector<vector<int>> &dp)
    {
        if(t<0)return 0;
        if(i==cost.size())return 1e9;
        if(dp[i][t]!=-1)return dp[i][t];
       int pick=cost[i]+solve(i+1,t-time[i]-1,cost,time,dp);
        int notPick=solve(i+1,t,cost,time,dp);
        return dp[i][t]=min(pick,notPick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,cost.size()-1,cost,time,dp); 
    }
};