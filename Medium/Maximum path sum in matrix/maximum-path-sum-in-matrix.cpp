//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int j, int n, vector<vector<int>> Mat, vector<vector<int>> &dp){
        if(j<0 || j>n-1 ) return 0;
        if(i==0) return Mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=Mat[i][j]+helper(i-1,j,n,Mat,dp);
        int rdag=Mat[i][j]+helper(i-1,j+1,n,Mat,dp);
        int ldag=Mat[i][j]+helper(i-1,j-1,n,Mat,dp);
        
        return dp[i][j]=max(up,max(ldag,rdag));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int res=-1e9;
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=0;i<N;i++) dp[0][i]=Matrix[0][i];
            
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int up=Matrix[i][j]+dp[i-1][j];
                int rdag=(j+1<N) ? Matrix[i][j]+dp[i-1][j+1]:0;
                int ldag=(j-1>=0) ? Matrix[i][j]+dp[i-1][j-1]:0;
                dp[i][j]=max(up,max(ldag,rdag));
            }
            
        }
        for(int i=0;i<N;i++) res=max(res,dp[N-1][i]);
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends