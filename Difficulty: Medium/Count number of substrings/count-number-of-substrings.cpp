//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int help(string s,int k)
    {
        long long int ans=0;
        int count=0;
        vector<int> freq(26,0);
        int l=0,r=0;
        int n=s.size();
        while(r<n)
        {
           freq[s[r]-'a']++;
           if(freq[s[r]-'a']==1)
           {
               count++;
           }
           while(count>k)
           {
               freq[s[l]-'a']--;
               if(freq[s[l]-'a']==0) count--;
               l++;
           }
          // if(count>=0)
           ans=ans+r-l+1;
           r++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	//code here 
    	long long int a=help(s,k);
    	long long int b=help(s,k-1);
    	
    	return a-b;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends