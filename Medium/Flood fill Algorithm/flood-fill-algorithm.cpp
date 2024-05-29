//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int> > &ans=image;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int color=image[sr][sc];
        ans[sr][sc]=newColor;
        queue<pair<int, int>> q;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==color && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=newColor;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;        // Code here 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends