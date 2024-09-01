//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int isvaild(int i,int j,int n,int m){
	   if(i < 0 || j < 0 || i >= n || j >= m ) return 0;
	   return 1;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[4] = {0,0,1,-1};
        int dc[4] = {-1,1,0,0};
        vis[0][0] = 1;
        int ans = -1;
        while(pq.size() > 0){
            int  a = pq.top().first;
            int b = pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();
            //cout<<a<<" "<<b<<" "<<c<<"\n";
            if(b == n-1 && c == m-1) return a;
            for(int i =0; i < 4;i++){
                int nr = dr[i] + b;
                int nc = dc[i] + c;
                if(isvaild(nr,nc,n,m) == 1 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    pq.push({grid[nr][nc]+a,{nr,nc}});
                }
            }
        }
        return -1;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends