class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(),ans=0;
        vector<int> maxb,maxe;
        maxb.push_back(h[0]);maxe.push_back(h[n-1]);
        for(int i=1,j=n-2;i<n;i++,j--)
        {
            maxb.push_back(max(maxb[i-1],h[i]));
            maxe.push_back(max(maxe[i-1],h[j]));
        }
        for(int i=0;i<=n/2;i++)
        {
            swap(maxe[i],maxe[n-1-i]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(maxb[i],maxe[i])-h[i];
        }
        return ans;
    }
};