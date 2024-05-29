//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        vector<bool>vis(26,0);
        int i=0;
        int j=0;
        int max=0;
        int len=0;
        while(i<S.size()){
            if(vis[S[i]-'a']==0){
                len=abs(j-i)+1;
                vis[S[i]-'a']=1;
            }
            else{
                while(vis[S[i]-'a']==1){
                    vis[S[j]-'a']=0;
                    j++;
                }
                 len=abs(j-i)+1;
                vis[S[i]-'a']=1;
            }
            if(max<len){
                max=len;
            }
            i++;
        }
        return max;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends