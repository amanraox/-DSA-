//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void summ(int ind, vector<int> &arr, int n, int sum, vector<int> &ds,vector<int> &s){
        if(ind==n){
            return;
        }
       
        ds.push_back(arr[ind]);
        sum+=arr[ind];
        s.push_back(sum);
        summ(ind+1, arr,n,sum,ds,s);
        sum-=arr[ind];
        summ(ind+1,arr,n,sum,ds,s);
        
    }
    public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ds;
        vector<int> s;
        summ(0,arr,n,0,ds,s);
        s.push_back(0);
        sort(s.begin(), s.end());
        return s;        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends