//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
int histoArea(int arr[], int m){
        stack<int> mystack;
        vector<int> left(m), right(m);
        
        for(int i= 0; i<m ; i++){
            if(mystack.empty()){
                left[i]=0; mystack.push(i);
            }
            else{
                while(!mystack.empty() && arr[mystack.top()]>=arr[i]){
                    mystack.pop();
                }
                left[i]= mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        
        while(!mystack.empty()) mystack.pop();
        
        for(int i=m-1; i>=0; i--){
            
            if(mystack.empty()){
                right[i]=m-1; mystack.push(i);
            }
            else{
                while(!mystack.empty() && arr[mystack.top()]>=arr[i]){
                    mystack.pop();
                }
                right[i]= mystack.empty()?m-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        
        int ans = INT_MIN;
        for(int i = 0; i<m ;i++){
            int temp = right[i]-left[i]+1;
            int temp2 = temp*arr[i];
            ans = max(ans, temp2);
        }
        
        return ans;
    }
    
    int largestRectangleArea(int heights[], int n) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int area = heights[top] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = largestRectangleArea(M[0], m);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == 0)
                    M[i][j] = 0;
                else
                    M[i][j] += M[i - 1][j];
            }
            ans = max(ans, largestRectangleArea(M[i], m));
        }
        return ans;        // Your code here
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends