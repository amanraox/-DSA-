//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
    int m=s.length();
    int n=t.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    
    for(int i=1;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=n;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends