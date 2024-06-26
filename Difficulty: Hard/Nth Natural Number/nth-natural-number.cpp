//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    	long long findNth(long long N)
    {
        long result = 0;
        long mul = 1;
        while(N>0){
            long num = N%9;
            if(num>=9){
                num++;
            }
            result+=num*mul;
            mul*=10;
            N/=9;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}


// } Driver Code Ends