//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		long long mod=1e9+7;
	    int dp_util(string str,int i,int n,vector<int>&dp)
	    {
	        if(i>n)
	        {
	            return 0;
	        }
	        if(i==n)
	        {
	            return 1;
	        }
	        if(dp[i]!=-1)
	        {
	            return dp[i];
	        }
	        int res=0;
	        if(str[i]=='0')
	        {
	            return 0;
	        }
	        if((i+1)<n and str.substr(i,2)<="26")
	        {
	            
	            res+=(dp_util(str,i+2,n,dp)%mod);
	        }
	        res+=(dp_util(str,i+1,n,dp)%mod);
	        return dp[i]=res%mod;
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    vector<int>dp(n,-1);
		    return dp_util(str,0,str.length(),dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends