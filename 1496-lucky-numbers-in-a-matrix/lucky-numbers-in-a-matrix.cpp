class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> ar,ac,ans;
            for(int i=0;i<n;i++)
            {   int rm=INT_MAX;
                for(int j=0;j<m;j++)
                rm=min(a[i][j],rm);
                ar.push_back(rm);
            }
            for(int i=0;i<m;i++)
            {   int cm=INT_MIN;
                for(int j=0;j<n;j++)
                cm=max(a[j][i],cm);
                ac.push_back(cm);
            }
            
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(a[i][j]==ar[i] and a[i][j]==ac[j])
        ans.push_back(a[i][j]);
        return ans;
    }
};