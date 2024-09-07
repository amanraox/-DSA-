//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        long long result = 0;
    
        long long p = 1;
    
        // Iterate while N is
        // greater than 0
        while (n > 0) {
    
          // Update result
          result += (p * (n % 9));
    
          // Divide N by 9
          n= n / 9;
    
          // Multiply p by 10
          p = p * 10;
        }
    
        // Return result
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends