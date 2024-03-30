//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
    if(n == 1) {
        return arr[0];
    } else if(n == 2) {
        return max(min(arr[0], arr[1]) * 2, max(arr[0], arr[1]));
    }
    stack<int> st;
    st.push(-1);
    vector<long long> NSL(n), NSR(n);
    
    for(int i = 0; i < n; i++) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        NSL[i] = st.top();
        
        st.push(i);
    }
    
    while(!st.empty()) {
        st.pop();
    }
    
    st.push(n);
    for(int i = n - 1; i >= 0; i--) {
        while(st.top() != n && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        NSR[i] = st.top();
        
        st.push(i);
    }
    
    long long ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        ans = max(ans, arr[i] * (NSR[i] - NSL[i] - 1));
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends