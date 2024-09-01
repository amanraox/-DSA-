class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if(o.size()!=m*n)return {};
        vector<vector<int>> a(m,vector<int>(n));
        int k=0,s=o.size();
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        a[i][j]=(o[k++]);
        return a;
    }
};