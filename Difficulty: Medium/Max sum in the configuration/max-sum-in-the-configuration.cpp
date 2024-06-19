//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
long long int sum=0;
        long long int maxi=0;
        
        for(int i=0;i<n;i++){
            sum+=(long long)a[i];
            maxi+=((long long)a[i]*i);
        }
        
        long long int now = maxi;
        
        for(int i=1;i<n;i++){
            now +=(sum - (long long)a[n-i]*(n) );
            
            maxi = max(maxi,now);
            
        }
        return maxi;    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends