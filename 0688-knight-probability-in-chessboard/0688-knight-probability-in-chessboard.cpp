class Solution {
public:
    int iarr[8] = {-2,-2,-1,-1,1,1,2,2};
    int jarr[8] = {-1,1,-2,2,-2,2,-1,1};
    double solve(int row,int col,int n,int k,vector<vector<vector<double>>> &dp){
        if(row < 0 or col < 0 or row >= n or col >= n) return 0;
        if(k == 0) return 1;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        
        double ans = 0.0;
        
        for(int i=0;i<8;i++){
            ans += solve(row+iarr[i], col+jarr[i], n, k-1, dp);
        }
        
        return dp[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>> (n+1,vector<double> (k+1,-1)));
        double fav = solve(row,col,n,k,dp);
        double total = pow(8,k);
        return fav/total;
    }
};