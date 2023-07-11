//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
       long long c[r+1];
        memset(c,0,sizeof(c));
        c[0]=1;
        int q=1000000007;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--){
                c[j]=(c[j]+c[j-1])%q;
            }
        }
        return c[r]%q;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends