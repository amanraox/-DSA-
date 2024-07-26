class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> check(n, vector<int>(n,1e8));
        for(int i=0; i<edges.size(); i++){
            int x= edges[i][0], y= edges[i][1], wt=edges[i][2];
            check[x][y]=wt; check[y][x]=wt;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) check[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                for(int k=0; k<n; k++){
                    if(check[j][i]+check[i][k] < check[j][k]){
                        check[j][k]=check[j][i]+check[i][k];
                    }
                }
            }
        }
        int ans=0, check1 =INT_MAX;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(check[i][j]<= threshold) count++;
            }
            if(count<=check1){
                check1=count;
                ans=i;
            }
        }
        return ans;
    }
};