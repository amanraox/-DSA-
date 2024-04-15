//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue <pair<pair<int,int>,int>> q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int count = q.front().second;
            q.pop();
            dis[row][col]= count;
            
            for(int i=0;i<4;i++){
                int nrow= row+ drow[i];
                int ncol= col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
	                q.push({{nrow,ncol},count+1});
	                visited[nrow][ncol]=1;
	            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1) return -1;
            }
        }
        int maxx=dis[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]>maxx) maxx=dis[i][j];
            }
        }
        return maxx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends