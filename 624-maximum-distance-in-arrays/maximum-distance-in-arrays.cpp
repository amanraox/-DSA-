class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mans=INT_MIN,mxd=a[0][a[0].size()-1],mid=a[0][0];
        for(int i=1;i<a.size();i++)
            mans=max({mans,abs(a[i][0]-mxd),abs(a[i][a[i].size()-1]-mid)}),mid=min(mid,a[i][0]),mxd=max(mxd,a[i][a[i].size()-1]);
        return mans;
    }
};