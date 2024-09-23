//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int a,b;
        for(int i=0;i<arr.size();i++){
            int x=abs(arr[i]);
            if(arr[x-1]<0){
                a=x;
            }
            else arr[x-1]=-arr[x-1];
        }
        
        
        for(int i=0;i<arr.size();i++){
             if(arr[i]>0)b=i+1;
        }
        return {a,b};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends