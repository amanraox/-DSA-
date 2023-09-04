//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dir[5] = {-1,0,1,0,-1};
void dfs(vector<vector<char>>& grid,int n,int m,int i,int j){
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!='O') return ;
    grid[i][j]='.';
    for(int k=0;k<4;k++){
        dfs(grid,n,m,i+dir[k],j+dir[k+1]);
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        // code here
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O') dfs(grid,n,m,i,0);
            if(grid[i][m-1]=='O') dfs(grid,n,m,i,m-1);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O') dfs(grid,n,m,0,j);
            if(grid[n-1][j]=='O') dfs(grid,n,m,n-1,j);
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                if(grid[i][j]=='.') grid[i][j]='O';
            }
        
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends