//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
        int n = s.size();
        int l = 0;
        int r = 1;
        while(r<n){
            char lc = s[l];
            char rc = s[r];
            if(lc == rc){
                if(s.substr(r) == s.substr(l,n-r)){
                    return n-r;
                }
            }
            r++;
        }
        return 0;
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends