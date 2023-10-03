//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {string ans="";
        while(n>0){
            int rem=n%26;
            if(rem){
                char c=rem-1 + 'A';
                string s;
                s.push_back(c);
                ans.insert(0,s);
                n=n/26;
            }else{
                ans.insert(0,"Z");
                n=n/26 - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends