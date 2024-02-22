//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t) 
    { 
      int n1=s.size(),n2 = t.size(),dp[n1+1][n2+1],mod = 1e9+7; 
        memset(dp,0,sizeof(dp)); 
        for(int i=0;i<=n1;i++){ 
            dp[i][0] = 1; 
        } 
        for(int i=1;i<=n1;i++){ 
            for(int j=1;j<=n2;j++){ 
                dp[i][j] = dp[i-1][j]; 
                if(s[i-1]==t[j-1]) 
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod; 
            } 
        } 
        return dp[n1][n2]; 
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends