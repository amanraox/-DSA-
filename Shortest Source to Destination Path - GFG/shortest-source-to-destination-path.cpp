//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
    {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int w=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(X==row && col==Y) return w;
            if(row-1>=0&&A[row-1][col]==1){
                q.push({w+1,{row-1,col}});
                A[row-1][col]=0;
            }
            if(col+1<M &&A[row][col+1]==1){
                q.push({w+1,{row,col+1}});
                A[row][col+1]=0;
            }
            if(row+1<N &&A[row+1][col]==1){
                q.push({w+1,{row+1,col}});
                A[row+1][col]=0;
            }
            if(col-1>=0 &&A[row][col-1]==1){
                q.push({w+1,{row,col-1}});
                A[row][col-1]=0;
            }
            
        }return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends