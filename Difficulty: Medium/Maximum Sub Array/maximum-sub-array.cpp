//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        int currStart = 0;
        int maxStart = 0;
        int maxEnd = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        
        for(int i = 0;i < n;i++){
            if(a[i] < 0){
                currSum = 0;
                currStart = i+1;
            }
            else{
                currSum += a[i];
            }
            
            if(currSum > maxSum){
                maxSum = currSum;
                maxStart = currStart;
                maxEnd = i;
            }
            else if(currSum == maxSum){
                  int currDis = i - currStart + 1;
                  int maxDis = maxEnd - maxStart + 1;
                  if(currDis > maxDis){
                      maxStart = currStart;
                      maxEnd = i;
                  }
            }
           
            
            
        }
        vector<int>ans;
        
        for(int i = maxStart;i <= maxEnd;i++){
            ans.push_back(a[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends