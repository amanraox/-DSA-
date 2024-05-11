//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int arr[], int i, int j) {
        if(i==j) return 0;
        int ans = INT_MAX;
        for(int k=i;k<j;k++) {
            ans = min(ans, rec(arr,i,k) + arr[i-1]*arr[k]*arr[j] + rec(arr,k+1,j));
        }
        return ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // int ans = rec(arr,1,N-1);
        // return ans;
        vector<vector<int> > dp(N, vector<int>(N, INT_MAX));
        for(int i=0;i<N;i++) dp[i][i] = 0;
        for(int i=N-1;i>=1;i--) {
            for(int j=i+1;j<N;j++) {
                int ans = INT_MAX;
                for(int k=i;k<j;k++) {
                    ans = min(ans, dp[i][k] + arr[i-1]*arr[k]*arr[j] + dp[k+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends