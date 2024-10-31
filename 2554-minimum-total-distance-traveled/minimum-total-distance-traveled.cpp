class Solution {
    #define ll long long
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), N = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        ll dp[101][101][101];
        ll inf = 1e15;
        memset(dp, inf, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<N; j++){
                int xR=robot[i], xF=factory[j][0], cap=factory[j][1];
                ll nottake = (j==0) ? inf : dp[i][j-1][0];
                dp[i][j][cap] = nottake;
                for(int k=0; k<cap; k++){
                    ll take = (i==0) ? abs(xR-xF) : abs(xR-xF) + dp[i-1][j][k+1];
                    dp[i][j][k] = min(take, nottake);
                }

            }
        }
        return dp[n-1][N-1][0];
    }
};