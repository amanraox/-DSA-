//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    void fun(vector<int>&arr, vector<int>&v)
    {
        stack<int>s;
        s.push(0);
        s.push(arr[0]);
        int n = arr.size();
        for(int i = 1 ; i < n ; i++)
        {
            while(s.top() >= arr[i]){s.pop();}
            v.push_back(s.top());
            s.push(arr[i]);
        }
        return;
    }
    int findMaxDiff(vector<int> &arr) 
    {
        // Your code here
        vector<int>left, right;
        int leftMin = 0, rightMin = 0;
        int n = arr.size();
        left.push_back(0);
        fun(arr, left);
        reverse(arr.begin(), arr.end());
        right.push_back(0);
        fun(arr, right);
        reverse(right.begin(), right.end());
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int diff = abs(left[i]-right[i]);
            ans = max(ans, diff);
        }
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends