class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if(o.size()!=m*n)return {};
        vector<vector<int>> a(m);
        int k=0,s=o.size();
        for(int i=0;i<m and k<s;i++)
        for(int j=0;j<n and k<s;j++,++k)
        a[i].push_back(o[k]);
        return a;
    }
};