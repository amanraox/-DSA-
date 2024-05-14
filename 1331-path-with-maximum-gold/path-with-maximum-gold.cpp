class Solution {
public:
int dfs(vector<vector<int>> &grid,int i,int j,int delrow[],int delcol[]){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]==0) return 0;
        int sum = grid[i][j];
        grid[i][j]=0;
        int maxi=0;
        for(int k=0;k<4;k++){
            int newrow = i+delrow[k];
            int newcol = j+delcol[k];
            maxi = max(maxi,dfs(grid,newrow,newcol,delrow,delcol));
        }
        grid[i][j]=sum;
        return maxi+sum;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,dfs(grid,i,j,delrow,delcol));
                }
            }
        }
        return ans;       
    }
};