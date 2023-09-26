//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
        vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n=arr.size();
        set<vector<int>>st;
        vector<vector<int>>ans;
        
        sort(arr.begin(),arr.end());
        
        
        
        for(int i=0; i<n-3; i++ ){
            for(int j=i+1; j<n-2; j++){
                
                int s=j+1; int e=n-1;
                while(s<e){
                    vector<int>temp;
                    
                    if((arr[i]+arr[j]+arr[s]+arr[e]) == k){
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[s]);
                        temp.push_back(arr[e]);
                        st.insert(temp);
                        s++;
                        e--;
                    }
                    
                    else if((arr[i]+arr[j]+arr[s]+arr[e]) >= k){
                        e--;
                    }
                    
                    else{
                        s++;
                    }
                }
            }
        }
        
        for(auto i : st){
            ans.push_back(i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends