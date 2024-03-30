//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string s, int i, int j, int isTrue, int dp[1001][1001][2]) {
        if (i > j)
            return false;
        if (i == j) {
            if (isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lF, lT, rT, rF;
            if (dp[i][k - 1][1] == -1) {
                lT = solve(s, i, k - 1, 1, dp);
            } else {
                lT = dp[i][k - 1][1];
            }

            if (dp[k + 1][j][1] == -1) {
                rT = solve(s, k + 1, j, 1, dp);
            } else {
                rT = dp[k + 1][j][1];
            }

            if (dp[i][k - 1][0] == -1) {
                lF = solve(s, i, k - 1, 0, dp);
            } else {
                lF = dp[i][k - 1][0];
            }

            if (dp[k + 1][j][0] == -1) {
                rF = solve(s, k + 1, j, 0, dp);
            } else {
                rF = dp[k + 1][j][0];
            }

            if (s[k] == '&') {
                if (isTrue == 1)
                    ans += (lT * rT) % 1003;
                else
                    ans += ((lF * rF) % 1003 + (lT * rF) % 1003 + (lF * rT) % 1003) % 1003;
            } else if (s[k] == '|') {
                if (isTrue == 1)
                    ans += ((lT * rT) % 1003 + (lT * rF) % 1003 + (lF * rT) % 1003) % 1003;
                else
                    ans += (lF * rF) % 1003;
            } else if (s[k] == '^') {
                if (isTrue == 1)
                    ans += ((lF * rT) % 1003 + (lT * rF) % 1003) % 1003;
                else
                    ans += ((lT * rT) % 1003 + (lF * rF) % 1003) % 1003;
            }
        }
        dp[i][j][isTrue] = ans % 1003;
        return dp[i][j][isTrue];
    }

    int countWays(int n, string s) {
        int dp[1001][1001][2];
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n - 1, 1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends