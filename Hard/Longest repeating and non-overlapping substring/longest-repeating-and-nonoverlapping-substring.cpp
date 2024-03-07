//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
int i = 0; 
    int j = 0; 
    string ans = "-1"; 
    int sz =0; 
    while(i<n && j<n) 
    { 
        string str = s.substr(i,(j-i+1)); 
        if(s.find(str,(j+1)) != string::npos) 
        { 
            if(str.size()>sz) 
            { 
                ans = str; 
                sz=str.size(); 
            } 
            j++; 
        } 
        else i++; 
    } 
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends