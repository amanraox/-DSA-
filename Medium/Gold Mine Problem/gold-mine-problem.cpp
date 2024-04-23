//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][m - 1] = M[i][m - 1];
        }
        
        for (int j = m - 2; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                int right = dp[i][j + 1];
                int up = (i > 0) ? dp[i - 1][j + 1] : 0;
                int down = (i < n - 1) ? dp[i + 1][j + 1] : 0;
                dp[i][j] = M[i][j] + max(right, max(up, down));
            }
        }
        
        int maxGold = 0;
        for (int i = 0; i < n; ++i) {
            maxGold = max(maxGold, dp[i][0]);
        }
        
        return maxGold;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends