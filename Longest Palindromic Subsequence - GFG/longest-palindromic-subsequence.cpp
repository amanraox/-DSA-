//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<int>>dp;
      int solve(string A,int i,int j){
      if(i>j)return 0;
      if(i==j)return 1;
      if(dp[i][j]!=-1)return dp[i][j];
      int maxx=-1e9;
      if(A[i]==A[j]){
          maxx=max(maxx,2+solve(A,i+1,j-1));
      }
      else{
          maxx=max(maxx,0+solve(A,i+1,j));
          maxx=max(maxx,0+solve(A,i,j-1));
      }
      return dp[i][j]=maxx;
  }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(A,0,n-1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends