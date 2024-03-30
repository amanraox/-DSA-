//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++)sum+=arr[i];
	    int dp[n+1][sum+1];
	    for(int i=0; i<=n; i++)dp[i][0]=1;
	    for(int i=1; i<=sum; i++)dp[0][i]=0;
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            dp[i][j] = j-arr[i-1] >=0 ? dp[i-1][j-arr[i-1]] || dp[i-1][j] : dp[i-1][j];
	        }
	    }
	    int ans = 1000007;
	    for(int i=0; i<=sum/2; i++){
	        if(dp[n][i])ans = min(ans, sum-2*i);
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends