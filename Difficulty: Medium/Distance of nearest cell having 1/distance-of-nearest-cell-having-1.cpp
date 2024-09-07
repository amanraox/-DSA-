//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>Vis(n,vector<int>(m,0));
        // pushing all one into the queue and made Vis 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        //we will create drow,dcol
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        // Now we will run while loop
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row1=row+drow[i];
                int col1=col+dcol[i];
                if(row1>=0 && row1<n && col1>=0 && col1<m && grid[row1][col1]==00 && !Vis[row1][col1]){
                    Vis[row1][col1]=dist+1;
                    q.push({{row1,col1},dist+1});
                    
                }
                
            }
        }
        return Vis;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends