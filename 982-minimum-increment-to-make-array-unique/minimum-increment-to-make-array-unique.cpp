class Solution {
public:
    int minIncrementForUnique(vector<int>& z) {
        sort(z.begin(),z.end());
        int n=z.size(),ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(z[i]>=z[i+1])
            {
                int te=z[i]-z[i+1];
                z[i+1]+=(te+1);
                ans+=(te+1);
            }
        }
        return ans;
    }
};