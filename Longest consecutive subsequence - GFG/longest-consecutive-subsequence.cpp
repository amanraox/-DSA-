//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      sort(arr,arr+N);
      
      int maxi=INT_MIN;
      int cnt=1;
      if(N==1)return 1;
      for(int i=1;i<N;i++){
          if(arr[i]-arr[i-1]==1){
              cnt++;
              
          }
          if(arr[i]-arr[i-1]==0)continue;
          else if(arr[i]-arr[i-1]>1){
              cnt=1;
          }
          maxi=max(maxi,cnt);
          
          
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends