//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        int count=0;
        sort(arr,arr+n);
     
                for(int k=n-1;k>0;k--)
                {
                    int i=0;
                    int j=k-1;
                    while(i<j)
                    {
                        if(arr[i]+arr[j]>arr[k])
                        {
                            count=count+(j-i);
                            j--;
                        }
                        else
                            i++;
                    }
                }
       
        return count;
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends