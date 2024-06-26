//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
 int check(vector<int>&v, int num){
        int ans=1,last=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]-last >=num){
                ans++;
                last=v[i];
            }
        }
        return ans;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int left=1,right=stalls[n-1]-stalls[0];
        while(left<=right){
            int mid=(left+right)/2;
            if(check(stalls,mid)<k) right=mid-1;
            else left=mid+1;
        }
        return right;    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends