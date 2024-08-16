class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mans=INT_MIN,mxd=a[0].back(),mid=a[0][0];
        for(int i=1;i<a.size();i++)
            mans=max({mans,abs(a[i][0]-mxd),abs(a[i].back()-mid)}),mid=min(mid,a[i][0]),mxd=max(mxd,a[i].back());
        return mans;
    }
};