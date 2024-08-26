//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if (n <= 1)
            return 0;
            
         if(arr[0] == 0)
            return -1;
        
        int maxl = 0;
        int m = 0;
        int jump = 0;
        
        for(int i=0; i<n; i++){
            if(i+arr[i]>maxl)
                maxl = max(maxl, i+arr[i]);
            if(i == m){
                m=maxl;
                jump++;
                if (m >= n-1)
                    return jump;
               
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends