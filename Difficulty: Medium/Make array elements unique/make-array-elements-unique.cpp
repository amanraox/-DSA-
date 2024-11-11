//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        int out = 0;
        sort(arr.begin(), arr.end());
        int prev = arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] <= prev)
            {
                out += (prev + 1 - arr[i]);
                prev = prev + 1;
            }
            else prev = arr[i];
        }
        return out;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends