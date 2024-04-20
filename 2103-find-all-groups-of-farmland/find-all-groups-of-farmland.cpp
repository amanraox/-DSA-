class Solution {
public:
vector<vector<int>> ans;
    vector<int> temp;
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    int lx = -1 , ly = -1;
    void bfs(int i, int j, int &n, int &m, vector<vector<int>>& land, vector<vector<int>>& vis){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            lx = qx;
            ly = qy;
            for(int k = 0; k < 2; k++){
                int nx = qx + x[k];
                int ny = qy + y[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 1 && land[nx][ny] == 1){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            } 
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){

                if(land[i][j] == 1 && vis[i][j] == 0){
                    lx = i;
                    ly = j;
                    bfs(i,j,n,m,land,vis);
                    ans.push_back({i,j,lx,ly});
                }
            }
        }

        return ans;        
    }
};