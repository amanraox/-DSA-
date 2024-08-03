class Solution {
public:
    int minFlips(vector<vector<int>>& g) {
        int a1=0,a2=0,r=g.size(),c=g[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c/2;j++)
            {
                if(g[i][j]!=g[i][c-j-1])++a1;
            }
        }
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r/2;j++)
            {
                if(g[j][i]!=g[r-j-1][i])++a2;
            }
        }
        return min(a1,a2);
    }
};