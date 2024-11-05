//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int factorial(int n){
        long long ans=n;
        while(--n)ans*=n;
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends