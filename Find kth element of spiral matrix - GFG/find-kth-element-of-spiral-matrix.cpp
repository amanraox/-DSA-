//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		vector<int> v;
 		int l=0,r=m-1,u=0,d=n-1;
 		while(l<=r && u<=d)
 		{
 		    for(int i=l;i<=r;i++) v.push_back(a[u][i]);
 		    u++;
 		    for(int i=u;i<=d;i++) v.push_back(a[i][r]);
 		    r--;
 		    for(int i=r;i>=l;i--) v.push_back(a[d][i]);
 		    d--;
 		    for(int i=d;i>=u;i--) v.push_back(a[i][l]);
 		    l++;
 		}
 		return v[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends